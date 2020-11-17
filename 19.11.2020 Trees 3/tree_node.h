#ifndef TREE_NODE
#define TREE_NODE
#include "student.h"

class Tree_node: public Student
{
	private:
		Tree_node * level = nullptr;
		Tree_node * down = nullptr;
		
		void destroy_node (void);
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