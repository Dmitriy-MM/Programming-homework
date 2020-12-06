#include <stdio.h>


template <class T> class B_tree;
template <class T>
class B_tree_node // : public T
	{
	private:
		T * values = nullptr; //  2*m elements array.
		int size = 0; // number of children.
		B_tree_node ** children = nullptr; //  2*m+1 elements array.
		
		
	public:
		enum RET_CODES {
			SUCCESS = 0,
			ERROR_MEMORY_ALLOC
		};
		B_tree_node () = default;
		int init (int m)
		{
			int i;
			size = 0;
			if (values != nullptr)
				return SUCCESS;
			fflush (stdout);
			values = new T[2*m];
			if (values == nullptr)
			{
				printf ("ERROR, can't allocate memory for <values>\n");
				return ERROR_MEMORY_ALLOC;
			}
			
			children = new B_tree_node<T>*[2*m+1];
			if (children == nullptr)
			{
				printf ("ERROR, can't allocate memory for <children>\n");
				return ERROR_MEMORY_ALLOC;
			}
			for (i = 0; i <= 2*m; i++)
			{
				children[i] = nullptr;
			}
			return SUCCESS;
		}
		
		B_tree_node (int m)
		{
			init (m);
		}
		~B_tree_node()
		{
			int i;
			
			delete[] values;
			for (i = 0; i <= size; i++)
				children[i] = nullptr;
			delete[] children;
		}
		B_tree_node (B_tree_node&& x): T ((T&&) x)
		{
			this->size = x.size;
			this->values = x.values;
			this->children = x.children;
			x.size = 0;
			x.values = nullptr;
			x.children = nullptr;
		}
		
		friend class B_tree<T>;
	};
	
template <class T>
class B_tree
	{
	private:
		int m; // B-tree base.
		B_tree_node<T> * root = nullptr;
		
		void destroy_tree (B_tree_node<T> * node)
		{
			int i = 0;
			
			for (i = 0; i <= 2*m; i++)
			{
				if (node->children[i] != nullptr)
				{
					destroy_tree (node->children[i]);
				}
			}
			delete node;
		}
		
		// вставить элемент x по индексу index, и указатель н потомка q по индексу index+1
		void insert_at (const T&x, B_tree_node<T> * where, int size, int index, B_tree_node<T> * q)
		{
			int i;
			(void) size;
			for (i = 2*m-1; i > index; i--)
			{
				where->values[i] = (T&&) where->values[i-1];
				where->children[i+1] = where->children[i];
			}
			where->values[index] = x;
			where->children[index+1] = q;
			where->size++;
		}

		void add_to_tree (B_tree_node<T> * root, const T& x)
		{
			if (root == nullptr)
			{
				root = new B_tree_node<T> (m);
				root->values[0] = x;
				root->size = 1;
				this->root = root;
				return;
			}
			T y;
			B_tree_node<T> * first = root, *second = nullptr;
			if (add_to_subtree (x, first, second, y)) 
				return;
			
			root = new B_tree_node<T> (m);
			root->values[0] = (T&&) y;
			root->children[0] = first;
			root->children[1] = second;
			root->size = 1;
			this->root = root;
		}
		
		bool add_to_subtree (const T &x, B_tree_node<T> *& first, B_tree_node<T> *& second, T & y)
		{
			int index;
			
			index = bin_search (x, first);
			// Теперь в index лежит номер "первого элемента из массива first->values, который >= x".
			B_tree_node<T> * p = first->children[index];
			// Теперь p указывает на узел который лежит ниже и левее 
			// "первого элемента из массива first->values, который >= x".
			// Соответственно если p == nullptr, 
			// то это значит что придется добавлять в текущий узел.
			if (p != nullptr)
			{
				// Если такой узел есть, то пытаемся рекурсивно добавить в него x.
				if (add_to_subtree (x, p, second, y)) return true;
			}
			else
			{
				second = nullptr;
				y = x;
			}
			
			
			if (first->size < 2*m)
			{
				// Вставляем в текущий узел.
				insert_at (y, first, first->size, index, second);
				return true;
			}
			else 
			{
				// Пытаемся добавить элемент в заполненный узел, для этого
				// представляем его значения и y, как упоряд. массив длины 2m+1, 
				// и его 2m+1 ссылок и ссылку second как упоряд. массив длины 2m+2.
				int i, pos;
				p = new B_tree_node<T> (m);
				T * vals = new T[2*m+1];
				B_tree_node<T> ** childs = new B_tree_node<T>*[2*m+2];
					
				for (i = 0; i < 2*m+1; i++)
					childs[i] = nullptr;
				
				pos = bin_search (y, first);
				// Собираем всех студентов в массив длины 2m+1, 
				// находим медианный и в соответствии с этим делим узел.
				for (i = 0; i < pos; i++)
				{
					vals[i] = (T &&) first->values[i];
					childs[i] = first->children[i];
				}
				vals[i] = (T&&) y;
				childs[i] = first->children[i];
				childs[i+1] = second;
				
				for (i = pos; i < m*2; i++)
				{
					vals[i+1] = (T &&) first->values[i];
					childs[i+2] = first->children[i+1];
				}
				// Теперь в vals 2m+1 студентов, причем этот массив упорядочен,
				// т.е. x стоит на своем месте.
				// А в childs 2m+2 ссылок, причем ссылки лежат в порядке,
				// соответствуеющем массиву vals.
				for (i = 0; i < m; i++)
				{
					first->values[i] = (T&&) vals[i];
					first->children[i] = childs[i];
				}
				first->children[i] = childs[i];
				first->size = i;
				for (i = m; i < 2*m; i++)
				{
					p->values[i-m] = (T&&) vals[i+1];
					p->children[i-m] = childs[i+1]; 
					first->children[i+1] = nullptr;
				}
				p->children[m] = childs[2*m+1];
				first->children[m+m] = nullptr;
				p->size = i-m;
				y = (T&&) vals[m];
				second = p;
				delete[] vals;
				delete[] childs;
				return false;
			}
		}

	public:
		B_tree () = default;
		void init (int m)
		{
			this->m = m;
		}
		B_tree (int m)
		{
			init (m);
		}
		~B_tree ()
		{
			if (root != nullptr)
				destroy_tree (root);
		}
		
		enum B_tree_CODES
		{
			SUCCESS = 0,
			ERROR_OPEN_FILE,
			NON_ZERO_ROOT_PTR,
			ERROR_READ_CURR,
			ERROR_READ_ROOT,
			ERROR_NOT_REACH_EOF
		};
		static void error_handler (int er_code)
		{
			printf ("B-tree error handler: ");
			switch (er_code)
			{
				case SUCCESS:
					printf ("All ok\n");
					break;
				case ERROR_OPEN_FILE:
					printf ("Can't open a file\n");
					break;
				case ERROR_READ_CURR:
					printf ("Error with copy from \"tmp\" to \"curr\"\n");
					break;
				case ERROR_NOT_REACH_EOF:
					printf ("Can't reach EOF\n");
					break;
				case NON_ZERO_ROOT_PTR:
					printf ("NON_ZERO_ROOT_PTR\n");
					break;
				default:
					printf ("Unknown error (%d)\n", er_code);
			}
		}
		
		int read (const char * filename)
		{
			FILE *fp = nullptr;
			T tmp;
		
			if (root != nullptr)
			{
				return NON_ZERO_ROOT_PTR;
			}
		
			fp = fopen (filename, "r");
			if (fp == nullptr)
			{
				return ERROR_OPEN_FILE;
			}
			while (tmp.read (fp) == T::SUCCESS)
			{
				add_to_tree (root, tmp);
			}
			if (!feof (fp))
			{
				fclose (fp);
				return ERROR_NOT_REACH_EOF;
			}
			fclose (fp);
			return SUCCESS;
		}
		
		int bin_search (const T& x, B_tree_node<T>* node)
		{
			T c;
			int inf = 0, sup = node->size, med;
			
			// Возвращает индекс первого элемента >= x;
			while (sup != inf)
			{
				med = (inf + sup) / 2;
				if (node->values[med] >= x)
				{
					sup = med;
				}
				else
					inf = med+1;		
			}
			return sup;
		}
		
		void print (int r)
		{
			if (root == nullptr)
				printf ("Empty B-tree\n");
			else
				print_to_level (root, 0, r);
		}
		void print_to_level (B_tree_node<T> * node, int level, int max_level)
		{
			int i, j;
			
			if (level >= max_level)
				return;
			
			if (node == nullptr)
			{
				
				printf ("Empty node\n");
				return;
			}
			for (i = 0; (i < node->size) && (i < max_level); i++)
			{
				for (j = 0; j < level-1; j++)
				{
					printf ("   |");
				}
				if (j < level)
					printf ("   ");
				printf ("%d) ", i);
				node->values[i].print ();
				printf ("\n");
			}
			if (i != 0)
			{
				if ((i >= max_level) && (i < node->size))
					printf ("...\n");
			}
			
			if (node->children != nullptr)
			{
				for (i = 0; (i <= node->size) && (i < max_level); i++)
				{
						print_to_level (node->children[i], level + 1, max_level);
				}
				if (i != 0)
				{
					if ((i >= max_level) && (i < node->size))
					{
						for (j = 0; j < level-1; j++)
						{
							printf ("   |");
						}
						if (j < level)
							printf ("   ");
						printf ("...\n");
					}	
				}
			}
		}
		// -------------------------------------------------------------
		// Tasks.
		
		// Возврщает количество детей данного узла.
		int count_children (B_tree_node<T> * pos)
		{
			B_tree_node<T> * curr = nullptr;
			B_tree_node<T> ** childs = nullptr;
			int result = 0, i;
			
			if (pos == nullptr)
				return 0;
			
			childs = pos->children;
			for (i = 0; i < pos->size+1; i++)
			{
				curr = childs[i];
				if (curr != nullptr)
					result++;
			}
			return result;
		}
		
		// Возврщает количество элементов в узлах,
		// имеющих ровно k потомков (детей).
		int task01 (int k, B_tree_node<T> * pos = nullptr)
		{
			B_tree_node<T> * curr = nullptr;
			B_tree_node<T> ** childs = nullptr;
			int result = 0, count_of_descendants;
			int i;
			
			if (pos == nullptr)
				pos = root;
				
			count_of_descendants = count_children (pos);
			if (count_of_descendants == k)
				result += pos->size;
			childs = pos->children;
			for (i = 0; i < pos->size+1; i++)
			{
				curr = childs[i];
				if (curr != nullptr)
				{
					result += task01 (k, curr);
				}
			}
			return result;
		}
		// --------------------------------------------------------------
		
		// Возврщает количество потомков данного узла, 
		// а в count_elem считает количество элементов в этом дереве.
		int count_descendants (B_tree_node<T>  * pos, int& count_elem)
		{
			B_tree_node<T>  * curr = nullptr;
			B_tree_node<T> ** childs = nullptr;
			int i;
			int result = 0;
			
			if (pos == nullptr)
				return 0;
			
			childs = pos->children;	
			for (i = 0; i < pos->size+1; i++)
			{
				curr = childs[i];
				if (curr != nullptr)
				{
					result += 1 + count_descendants (curr, count_elem);
				}
			}
			count_elem += pos->size;
			
			return result;
		}

		
		// Возврщает количество элементов в поддеревьях,
		// имеющих не более k вершин.
		int task02 (int k, B_tree_node<T>  * pos = nullptr)
		{
			B_tree_node<T> * curr = nullptr;
			B_tree_node<T> ** childs = nullptr;
			int i;
			int result = 0, count = 0;
			
			if (pos == nullptr)
				pos = root;
			// Считаем для узла.
			if (1 + count_descendants (pos, count) <= k)
				result += count;
				
			// Запуск для потомков.
			childs = pos->children;			
			for (i = 0; i < pos->size+1; i++)
			{
				curr = childs[i];
				if (curr != nullptr)
				{
					result += task02 (k, curr);
				}
			}
			return result;
		}
		// --------------------------------------------------------------
		
		// Возврщает количество уровней поддерева, образованного данным узлом, 
		// в count считает количество элементов в этом поддереве.
		int get_max_deep (B_tree_node<T> * pos, int& count)
		{
			B_tree_node<T> * curr = nullptr;
			B_tree_node<T> ** childs = nullptr;
			int deep = 1, max_deep = 1, deep_down;
			int i;
			
			if (pos == nullptr)
				return 0;
			
			childs = pos->children;			
			for (i = 0; i < pos->size+1; i++)
			{
				curr = childs[i];
				deep_down = get_max_deep (curr, count);
				deep += deep_down;
				if (deep > max_deep)
					max_deep = deep;
				deep -= deep_down;
			}
			count += pos->size;
			
			return max_deep;
		}
		
		// Возврщает количество элементов в поддеревьях,
		// имеющих не более k уровней.
		int task03 (int k, B_tree_node<T> * pos = nullptr)
		{
			B_tree_node<T> * curr = nullptr;
			B_tree_node<T> ** childs = nullptr;
			int result = 0, deep;
			int count = 0, i;
			
			if (pos == nullptr)
				pos = root;
			
			deep = get_max_deep (pos, count);
			if (deep <= k)
			{
				result += count;
			}
			// Запуск для потомков.
			childs = pos->children;			
			for (i = 0; i < pos->size+1; i++)
			{
				curr = childs[i];
				if (curr != nullptr)
				{
					result += task03 (k, curr);
				}
			}
			return result;
		}
		// --------------------------------------------------------------
		
		// Возврщает количество элементов на n-ом уровне,
		// если до него можно дойти.
		int count_elems_in_level (B_tree_node<T> * pos, int lvl_to_go, int & count)
		{
			B_tree_node<T> * curr = nullptr;
			B_tree_node<T> ** childs = nullptr;
			int result = 0;
			int i;
			
			if (pos == nullptr)
				return 0;
			if (lvl_to_go == 0)
			{
				count += pos->size;
				return 1;
			}
			childs = pos->children;	
			for (i = 0; i < pos->size+1; i++)
			{
				curr = childs[i];
				result += count_elems_in_level (curr, lvl_to_go-1, count);
			}
			
			return result;
		}
		
		// Возврщает количество элементов в поддеревьях,
		// имеющих не более k узлов в любом уровне.
		int task04 (int k, B_tree_node<T> * pos = nullptr)
		{
			B_tree_node<T> * curr = nullptr;
			B_tree_node<T> ** childs = nullptr;
			int result = 0, second_res;
			int i, do_count, count_of_elems_in_subtree, count_of_elems;
			
			if (pos == nullptr)
				pos = root;
			
			// do_count - дерево имеет не более k узлов  в любом уровне (считать ли этот элемент).
			// count_elems_in_level - возвращает количество УЗЛОВ в уровне, 
			// а в count_of_elems записывает количество элементов в этом уровне.
			i = 0, do_count = 1, count_of_elems_in_subtree = 0, count_of_elems = 0;
			while ((second_res = count_elems_in_level (pos, i, count_of_elems)) > 0)
			{
				count_of_elems_in_subtree += count_of_elems;
				count_of_elems = 0;
				if (second_res > k)
				{
					do_count = 0;
					break;
				}
				i++;
			}
			if (do_count)
				result += count_of_elems_in_subtree;
					
			childs = pos->children;			
			for (i = 0; i < pos->size+1; i++)
			{
				curr = childs[i];
				if (curr != nullptr)
				{
					result += task04 (k, curr);
				}
			}
			return result;
		}
		
		// Возврщает количество элементов в k-ом уровне дерева.
		int task05 (int k)
		{
			int count = 0;
			count_elems_in_level (root, k, count);
			return count;
		}
		
		// Возврщает количество элементов во всех ветвях,
		// длины РОВНО (раньше было "не менее") k считая от корня до листа.
		int task06 (int k, B_tree_node<T> * pos = nullptr, int curr_lvl = 0, int cur_size = 0)
		{
			B_tree_node<T> * curr = nullptr;
			B_tree_node<T> ** childs = nullptr;
			int result = 0;
			int i;
			
			if (pos == nullptr)
				pos = root;
				
			cur_size += pos->size;
			
			childs = pos->children;			
			for (i = 0; i < pos->size+1; i++)
			{
				curr = childs[i];
				if (curr == nullptr)
				{
					if (curr_lvl+1 == k)
						return cur_size;
				}
				else
				{
					result += task06 (k, curr, curr_lvl+1, cur_size);
				}
			}
			return result;
		}
	};
	
	
