#ifndef TREE_NODE
#define TREE_NODE
#include "student.h"

class Tree_node: public Student
{
	private:
		Tree_node * left = nullptr;
		Tree_node * right = nullptr;
		
		void destroy_branch (void);
	public:
		friend class Tree;
		
		Tree_node (void) = default;
		~Tree_node (void);
		Tree_node (const Tree_node& nd);
		Tree_node (Tree_node&& nd);
		Tree_node& operator = (const Tree_node& nd);
		Tree_node& operator = (Tree_node&& nd);
};
#endif //TREE_NODE.