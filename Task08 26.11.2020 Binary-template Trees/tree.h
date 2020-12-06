#ifndef TREE
#define TREE

#include <stdio.h>

template <class T> class Tree;
template <class T> 
class Tree_node: public T
{
	private:
		Tree_node * left = nullptr;
		Tree_node * right = nullptr;
		
		void destroy_node (void)
		{
			right = nullptr;
			left = nullptr;
		}
	public:
		~Tree_node (void)
		{
			destroy_node ();
		}
		Tree_node (const Tree_node& nd): T (nd)
		{
			//При создании узла через конструктор будет создана
			//копия узла (содержимое T), но не будут скопированы ссылки.
			right = nullptr;
			left = nullptr;
		}
		Tree_node (Tree_node&& nd): T ((T&&) (nd))
		{
			right = nd.right;
			nd.right = nullptr;
			left = nd.left;
			nd.left = nullptr;
		}
		Tree_node& operator = (const Tree_node& nd)
		{
			*(T *) (this) = nd;
			return *this;
		}
		Tree_node& operator = (Tree_node&& nd)
		{
			*(T *) (this) = nd;
			right = nd.right;
			nd.right = nullptr;
			left = nd.left;
			nd.left = nullptr;
			return *this;
		}
		Tree_node (void) = default;
		
		friend class Tree<T>;
};


template <class T>
class Tree
{
	private:
		Tree_node<T> * root = nullptr;
		
		void  print_branch (int max_left, int left, Tree_node<T> * nd)
		{
			Tree_node<T> * curr = nullptr;
			int i, k;
			
			if (max_left <= left) return;
			
			
			for (curr = nd, k = 0; curr != nullptr; curr = curr->left, k++)
			{
				for (i = 0; i < left-1; i++)
					printf ("   |");
				if (i < left)
					printf ("   ");
				printf ("%d) ", k);
				curr->print ();
				printf ("\n");
				if (curr->right != nullptr)
					print_branch (max_left, left + 1, curr->right);
			}
		}

		void destroy_tree (Tree_node<T> * nd)
		{
			Tree_node<T> * curr = nullptr, *left = nullptr, * right = nullptr;
			
			
			for (curr = nd; curr != nullptr; curr = left)
			{
				right = curr->right;
				left = curr->left;
				delete curr;
				if (right != nullptr)
				{
					destroy_tree (right);
				}
			}
		}

		void add_node (Tree_node<T> * nd, Tree_node<T> * where)
		{
			if (where == nullptr) where = root;
			if (*nd < *where)
			{
				if (where->left == nullptr)
					where->left = nd;
				else
					add_node (nd, where->left);
			}
			else
			{
				if (where->right == nullptr)
					where->right = nd;
				else
					add_node (nd, where->right);
			}
		}
	public:
		enum RET_CODES {
			SUCCESS = 0,
			ERROR_OPEN_FILE,
			ERROR_READ_CURR,
			ERROR_NOT_REACH_EOF
			
		};
		
		int read (const char * filename)
		{
			FILE *fp = nullptr;
			Tree_node<T> tmp;
			Tree_node<T> * curr = nullptr;
			
			if (!(fp = fopen (filename, "r")))
				return ERROR_OPEN_FILE;
			
			while (tmp.read (fp) == T::SUCCESS)
			{
				curr = new Tree_node<T> ((Tree_node<T>&&)(tmp));
				if (curr == nullptr)
				{
					fclose (fp);
					return ERROR_READ_CURR;
				}
				if (root == nullptr)
					root = curr;
				else
					add_node (curr, root);
			}
			
			if (!feof (fp))
			{
				fclose (fp);
				return ERROR_NOT_REACH_EOF;
			}
			fclose (fp);
			return SUCCESS;
		}

		void print (int max_left)
		{
			if (root != nullptr)
				print_branch (max_left, 0, root);
			else
				printf ("Empty tree\n");
		}

		static void error_handler (int er_code)
		{
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
				default:
					printf ("Unknown error (error_handler())\n");
			}
		}
		
		~Tree ()
		{
			if (root != nullptr)
				destroy_tree (root);
			root = nullptr;
		}
		Tree () = default;
		
		
		//Возвращает количество студентов в концевых узлах дерева.
		int task01 (Tree_node<T> * pos = nullptr)
		{
			int res = 0;
	
			if (pos == nullptr)
			{
				if (root == nullptr)
					return 0;
				else
					pos = root;
			}
			if (pos->left != nullptr)
				res += task01 (pos->left);
			if (pos->right != nullptr)
				res += task01 (pos->right);
			
			if (res == 0) //Нету потомков - значит этот элемент сам есть концевой.
				return pos->get_length ();
			else
				return res;
		}
		
		//Возвращает количество студентов в самой большой ветви дерева.
		int task02 (Tree_node<T> * pos = nullptr)
		{
			int res, second_res;
			int length;
			
			if (pos == nullptr)
			{
				if (root == nullptr)
					return 0;
				else
					pos = root;
			}
			
			length = pos->get_length ();
			res = length;
			if (pos->left != nullptr)
			{
				second_res = length + task02 (pos->left);
				res = second_res > res? second_res: res;
			}
			if (pos->right != nullptr)
			{
				second_res = length + task02 (pos->right);
				res = second_res > res? second_res: res;
			}
			return res;
		}
		
		//Возвращает количество элементов на уровне дерева который подан, если до него возможно дойти.
		int task03_second (Tree_node<T> * pos, int level_to_go)
		{
			int result = 0;
			
			if (pos == nullptr)
				return 0;
			if (level_to_go == 0)
				return pos->get_length ();
			
			if (pos->left != nullptr)
				result += task03_second (pos->left, level_to_go-1);
			if (pos->right != nullptr)
				result += task03_second (pos->right, level_to_go-1);
			
			return result;
		}

		//Возвращает максимальное количество элементов в одном уровне дерева.
		int task03 (Tree_node<T> * pos = nullptr)
		{
			int cur, max = -1, i;
			
			if (pos == nullptr)
			{
				if (root == nullptr)
					return 0;
				else
					pos = root;
			}
			
			i = 0;
			while ((cur = task03_second (root, i)) != 0)
			{
				i++;
				if (cur > max)
					max = cur;
			}
			return max;
		}
		
		int task04_second (Tree_node<T> * pos)
		{
			int result = 0;
			
			result = pos->get_length ();
			
			if (pos->left != nullptr)
				result += task04_second (pos->left);
			if (pos->right != nullptr)
				result += task04_second (pos->right);
			return result;
		}
		
		
		//Возвращает максимальную разность между количеством студентов левого и правого поддеревьев в узлах дерева.
		int task04 (Tree_node<T> * pos = nullptr)
		{
			int result, second_res;
			int left_deep = 0, right_deep = 0;
			
			if (pos == nullptr)
			{
				if (root == nullptr)
					return 0;
				else
					pos = root;
			}
			
			if (pos->left != nullptr)
				left_deep = task04_second (pos->left);
			if (pos->right != nullptr)
				right_deep = task04_second (pos->right);
			
			//Модуль разности left_deep и right_deep.
			result = (left_deep > right_deep)? left_deep - right_deep: right_deep - left_deep;
			
			if (pos->left != nullptr)
			{
				second_res = task04 (pos->left);
				result = (result > second_res)? result: second_res;
			}
			if (pos->right != nullptr)
			{
				second_res = task04 (pos->right);
				result = (result > second_res)? result: second_res;
			}
			
			return result;
		}


		//Возвращает количество студентов в узлах, имеющих ровно одного потомка.
		int task05 (Tree_node<T> * pos = nullptr)
		{
			int result = 0;
			int is_right_exist, is_left_exist;
			
			if (pos == nullptr)
			{
				if (root == nullptr)
					return 0;
				else
					pos = root;
			}
			
			is_left_exist = (pos->left != nullptr);
			is_right_exist = (pos->right != nullptr);
			
			//Есть только один потомок.
			if (
				((is_left_exist && is_right_exist) == 0) &&
				((is_left_exist || is_right_exist) == 1)
			)
				result += pos->get_length ();
			if (is_left_exist)
				result += task05 (pos->left);
			if (is_right_exist)
				result += task05 (pos->right);
			
			return result;
		}
};
#endif //TREE.









