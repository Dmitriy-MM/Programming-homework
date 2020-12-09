#include <stdio.h>

//#define R_MARKER "-\x1b[31mR\x1b[0m "
#define R_MARKER "-r "
#define B_MARKER "-b "

template <class T> class RB_tree;
template <class T>
class RB_tree_node : public T
	{
	private:
		enum COLORS
			{
				INVALID,
				RED,
				BLACK
			};
		RB_tree_node * left = nullptr;
		RB_tree_node * right = nullptr;
		RB_tree_node * parent = nullptr;
		COLORS color = INVALID;
	public:
		enum RET_CODES {
			SUCCESS = 0,
			ERROR_MEMORY_ALLOC
		};
	
		RB_tree_node () = default;
		
		RB_tree_node (RB_tree_node&& x) : T ((T&&) x)
		{
			this->left = x.left;
			this->right = x.right;
			this->parent = x.parent;
			x.left = nullptr;
			x.right = nullptr;
			x.parent = nullptr;
		}
		
		~RB_tree_node ()
		{
			left = nullptr;
			right = nullptr;
			parent = nullptr;
			color = INVALID;
		}
		
		friend class RB_tree<T>;
	};
	
template <class T>
class RB_tree
	{
	private:
		int m; // B-tree base.
		RB_tree_node<T> * root = nullptr;
		
	public:
		RB_tree () = default;
		enum RB_tree_CODES
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
		
		int check_subtree (RB_tree_node<T> * root)
		{
			int res = 1;
			if (root->left != nullptr)
			{
				if (root->color == RB_tree_node<T>::RED)
					if (root->left->color == root->color)
						return 0;
				res = res & check_subtree (root->left);
			}
			if (root->right != nullptr)
			{
				if (root->color == RB_tree_node<T>::RED)
					if (root->right->color == root->color)
						return 0;
				res = res & check_subtree (root->right);
			}
			return res;
		}
		int check_tree ()
		{
			return check_subtree (root);
		}
		
		void destroy_subtree (RB_tree_node<T> * root)
		{
			RB_tree_node<T> * left = root->left, * right = root->right;
			delete root;
			if (left != nullptr)
				destroy_subtree (left);
			if (right != nullptr)
				destroy_subtree (right);
		}
		
		~RB_tree ()
		{
			destroy_subtree (root);
		}
		
		int read (const char * filename)
		{
			FILE *fp = nullptr;
			RB_tree_node<T> buf;
			RB_tree_node<T> * curr = nullptr;
		
			if (root != nullptr)
			{
				return NON_ZERO_ROOT_PTR;
			}
		
			fp = fopen (filename, "r");
			if (fp == nullptr)
			{
				return ERROR_OPEN_FILE;
			}
			while (buf.read (fp) == T::SUCCESS)
			{
				curr = new RB_tree_node<T> ((RB_tree_node<T>&&) buf);
				if (curr == nullptr)
				{
					fclose (fp);
					return ERROR_READ_CURR;
				}
				add_to_subtree (root, curr);
			}
			if (!feof (fp))
			{
				fclose (fp);
				return ERROR_NOT_REACH_EOF;
			}
			fclose (fp);
			return SUCCESS;
		}
		
		void add_to_subtree (RB_tree_node<T> *& root, RB_tree_node<T> * x, RB_tree_node<T> * parent = nullptr)
		{
			if (root == nullptr)
			{
				root = x;
				root->color = RB_tree_node<T>::RED;
				root->parent = parent;
				to_balance (x);
			}
			else if (*x <= *root)
				add_to_subtree (root->left, x, root);
			else
				add_to_subtree (root->right, x, root);
		}
		
		void to_balance (RB_tree_node<T> * x)
		{
			// x - стал корнем дерева.
			if (x->parent == nullptr)
			{
				x->color = RB_tree_node<T>::BLACK;
				return;
			// Добавили красный узел к чёрному - всё хорошо.
			} else if (x->parent->color == RB_tree_node<T>::BLACK) {
				return;
			// Конфликт красный-красный.
			} else {
				RB_tree_node<T> *g, *u = get_uncle(x);
				// Красный дядя.
				if ((u != nullptr) && (u->color == RB_tree_node<T>::RED)) {
					// && (n->parent->color == RED) Второе условие проверяется выше, то есть родитель уже является красным.
					x->parent->color = RB_tree_node<T>::BLACK;
					u->color = RB_tree_node<T>::BLACK;
					g = grandparent (x);
					g->color = RB_tree_node<T>::RED;
					to_balance (g);
				}  else {
					RB_tree_node<T> *g = grandparent(x);

					if ((x == x->parent->right) && (x->parent == g->left)) 
					{
						rotate_left(x->parent);
						x = x->left;
					} else if ((x == x->parent->left) && (x->parent == g->right)) {
						rotate_right(x->parent);
						x = x->right;
					}
					
					g = grandparent(x);
					x->parent->color = RB_tree_node<T>::BLACK;
					g->color = RB_tree_node<T>::RED;
					if ((x == x->parent->left) && (x->parent == g->left)) {
						rotate_right(g);
					} else { /* (n == n->parent->right) && (n->parent == g->right) */
						rotate_left(g);
					}
				}
			}
		}
		
		
		RB_tree_node<T> * get_uncle (RB_tree_node<T> * x)
		{
			if (x->parent == nullptr)
				return nullptr;
			if (x->parent->parent->left == x->parent)
				return x->parent->parent->right;
			else
				return x->parent->parent->left;
		}
		RB_tree_node<T> * grandparent (RB_tree_node<T> * x)
		{
			if ((x->parent != nullptr) && (x->parent->parent != nullptr))
				return x->parent->parent;
			return nullptr;
		}
		
		void rotate_left (RB_tree_node<T> * root) // Опускает корень вниз влево.
		{
			RB_tree_node<T> * parent = root->parent, * tmp = nullptr;
			int is_parent_left = 0;
			bool new_root = false;
			
			if (this->root == root)
				new_root = true;
				
			if ((parent != nullptr) && (root == parent->left))
				is_parent_left = 1;
			
			tmp = root->right;
			if (tmp == nullptr)
				return;
			root->right = tmp->left; 
			if (tmp->left != nullptr)
				tmp->left->parent = root;
			tmp->left = root; root->parent = tmp;
			if (is_parent_left)
				parent->left = tmp;
			else if (parent != nullptr)
				parent->right = tmp;
			tmp->parent = parent;
			
			if (new_root)
				this->root = tmp;
		}
		
		void rotate_right (RB_tree_node<T> * root)
		{
			RB_tree_node<T> * parent = root->parent, * tmp = nullptr;
			int is_parent_left = 0;
			bool new_root = false;
			
			if (this->root == root)
				new_root = true;
			
			if ((parent != nullptr) && (root == parent->left))
				is_parent_left = 1;
			
			tmp = root->left;
			if (tmp == nullptr)
				return;
			root->left = tmp->right; 
			if (tmp->right != nullptr)
				tmp->right->parent = root;
			tmp->right = root; root->parent = tmp;
			if (is_parent_left)
				parent->left = tmp;
			else if (parent != nullptr)
				parent->right = tmp;
			tmp->parent = parent;
			
			if (new_root)
				this->root = tmp;
		}
		
		void print (int max_level)
		{
			if (root != nullptr)
			{
				print_branch (max_level, 0, root);
			}
			else
				printf ("Empty tree\n");
		}

		void print_branch (int max_level, int level, RB_tree_node<T> * nd, int position = 0)
		{
			int spaces = level-1;
			int i;
			
			if (max_level <= level) return;
			for (i = 0; i < spaces; i++)
				printf (" |");
			if (i < level)
				printf (" ");
			
			if (position == -1)
				printf ("L");
			else if (position == 1)
				printf ("R");
			else 
				printf ("H");
				
			if (nd->color == RB_tree_node<T>::RED)
				printf (R_MARKER);
			else 
				printf (B_MARKER);
			nd->print ();
			printf ("\n");
			if (nd->left)
			{
				print_branch (max_level, level + 1, nd->left, -1);
			}
			if (nd->right)
			{
				print_branch (max_level, level + 1, nd->right, 1);
			}
		}
		
		// -------------------------------------------------------------
		// Tasks.
		
		//Возвращает количество элементов в поддереве.
		int get_count_elems (RB_tree_node<T> * pos, int k)
		{
			int count = 1;
			
			if (pos == nullptr)
			{
				if (root == nullptr)
					return 0;
				else
					pos = root;
			}
			
			if (pos->left != nullptr)
				count += get_count_elems (pos->left, k);
			if (pos->right != nullptr)
				count += get_count_elems (pos->right, k);
			
			return count;
		}

		//Возвращает длину самой большой ветки дерева.
		int get_length (RB_tree_node<T> * pos)
		{
			int res = 1, second_res;
			
			if (pos == nullptr)
			{
				if (root == nullptr)
					return 0;
				else
					pos = root;
			}
			if (pos->left != nullptr)
			{
				second_res = 1 + get_length (pos->left);
				res = second_res > res? second_res: res;
			}
			if (pos->right != nullptr)
			{
				second_res = 1 + get_length (pos->right);
				res = second_res > res? second_res: res;
			}
			return res;
		}

		int task01 (int k, RB_tree_node<T> * pos = nullptr)
		{
			int res = 0, count = 0;
			
			if (pos == nullptr)
			{
				if (root == nullptr)
					return 0;
				else
					pos = root;
			}
			
			//Проверить есть ли у текущего дерева k вершин?
			count = get_count_elems (pos, k);
			if (count <= k)
				res = count;
			
			if (pos->left != nullptr)
				res += task01 (k, pos->left);
			if (pos->right != nullptr)
				res += task01 (k, pos->right);
			return res;
		}
		
		//Возвращает количество элементов в поддеревьях в которых не более k уровней.
		int task02 (int k, RB_tree_node<T> * pos = nullptr)
		{
			int res = 0, length = 0;
			
			if (pos == nullptr)
			{
				if (root == nullptr)
					return 0;
				else
					pos = root;
			}
			
			//Проверить есть ли у текущего дерева k уровней?
			length = get_length (pos);
			if (length <= k)
				res += get_count_elems (pos, k);
			
			if (pos->left != nullptr)
				res += task02 (k, pos->left);
			if (pos->right != nullptr)
				res += task02 (k, pos->right);
			return res;
		}

		
		
		//Возвращает количество элементов в поддеревьях у которых не более k элементов в любом уровне.
		int task03 (int k, RB_tree_node<T> * pos = nullptr)
		{
			int cur, i, res = 0, second_sum = 0;
			bool do_count = true;
			
			if (pos == nullptr)
			{
				if (root == nullptr)
					return 0;
				else
					pos = root;
			}
			
			i = 0;
			cur = task04 (i, pos);
			while (cur != 0)
			{
				if (cur > k)
				{
					do_count = false;
					break;
				}
				second_sum += cur;
				i++;
				cur = task04 (i, pos);
			}
			
			if (cur == 0)
			{
				if (do_count)
					res += second_sum;
			}
			
			if (pos->left != nullptr)
				res += task03 (k, pos->left);
			if (pos->right != nullptr)
				res += task03 (k, pos->right);
			
			return res;
		}


		//Возвращает количество элементов в k-ом уровне.
		int task04 (int level_to_go, RB_tree_node<T> * pos = nullptr)
		{
			int result = 0;
			
			if (pos == nullptr)
			{
				if (root == nullptr)
					return 0;
				else
					pos = root;
			}
			if (level_to_go == 0)
				return 1;
			
			if (pos->left != nullptr)
				result += task04 (level_to_go-1, pos->left);
			if (pos->right != nullptr)
				result += task04 (level_to_go-1, pos->right);
			
			return result;
		}
		
		// Возврщает количество элементов во всех ветвях,
		// длины РОВНО (раньше было "не менее") k считая от корня до листа.
		int task05 (int k, RB_tree_node<T> * pos = nullptr, int curr_lvl = 0, int cur_size = 0)
		{
			int result = 0;
			
			if (pos == nullptr)
				pos = root;
				
			cur_size++;
						
			if ((pos->left == nullptr) && (pos->right == nullptr))
			{
				if (curr_lvl+1 == k)
				 return cur_size;
			}
			
			if (pos->left != nullptr)
			{
				result += task05 (k, pos->left, curr_lvl+1, cur_size);
			}
			if (pos->right != nullptr)
			{
				result += task05 (k, pos->right, curr_lvl+1, cur_size);
			}
			
			return result;
		}

	};
	
	









