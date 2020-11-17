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
		void destroy_tree (Tree_node * nd = nullptr);
		
		int count_descendants (Tree_node * pos);
		int get_max_deep (Tree_node * pos);
		int count_elems_in_level (Tree_node * pos, int lvl_to_go);
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
		
		~Tree (void);

		Tree () = default;
		
		int task01 (int k, Tree_node * pos = nullptr);
		int task02 (int k, Tree_node * pos = nullptr);
		int task03 (int k, Tree_node * pos = nullptr);
		int task04 (int k, Tree_node * pos = nullptr);
		int task05 (int k);
		int task06 (int k, Tree_node * pos = nullptr, int curr_lvl = 0);
};
#endif //TREE.
