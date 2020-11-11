#ifndef TREE
#define TREE

#include <stdio.h>
#include "tree_node.h"

class Tree
{
	private:
		Tree_node * root = nullptr;
		
		void add_node (Tree_node *, Tree_node *);
		void print_branch (int max_level, int level, Tree_node * nd);
		
		int get_count_elems (Tree_node * pos, int k);
		int get_length (Tree_node * pos);
	public:
		enum RET_CODES {
			SUCCESS = 0,
			ERROR_OPEN_FILE,
			ERROR_READ_CURR,
			ERROR_NOT_REACH_EOF
			
		};
		static void error_handler (int);
		int read (const char *);
		void print (int);
		~Tree (void)
		{
			if (root != nullptr)
				delete root;
			root = nullptr;
		}

		Tree () = default;
		int task01 (int k, Tree_node * pos = nullptr);
		int task02 (int k, Tree_node * pos = nullptr);
		int task03 (int k, Tree_node * pos = nullptr);
		int task04 (int k, Tree_node * pos = nullptr);
		int task05 (int k, Tree_node * pos = nullptr);
};

#endif //TREE.
