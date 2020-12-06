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
		
		int task03_second (Tree_node * pos, int level_to_go);
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
		int task01 (Tree_node * pos = nullptr);
		int task02 (Tree_node * pos = nullptr);
		int task03 (Tree_node * pos = nullptr);
		int task04 (Tree_node * pos = nullptr);
		int task05 (Tree_node * pos = nullptr);
};

#endif //TREE.
