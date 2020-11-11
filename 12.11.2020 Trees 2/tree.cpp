#include "tree.h"

void Tree::add_node (Tree_node * nd, Tree_node * where)
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

int Tree::read (const char * filename)
{
	FILE *fp = nullptr;
	Tree_node tmp;
	Tree_node * curr = nullptr;
	
	if (!(fp = fopen (filename, "r")))
		return ERROR_OPEN_FILE;
	while (tmp.read (fp) == Student::SUCCESS)
	{
		curr = new Tree_node ((Tree_node&&)(tmp));
		if (curr == nullptr )
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

void Tree::print (int max_level)
{
	if (root != nullptr)
		print_branch (max_level, 0, root);
	else
		printf ("Empty tree\n");
}

void Tree:: print_branch (int max_level, int level, Tree_node * nd)
{
	int spaces = level * 2;
	int i;
	
	if (max_level < level) return;
	for (i = 0; i < spaces; i++)
		printf (" ");
	nd->print ();
	printf ("\n");
	if (nd->left)
	{
		printf ("L");
		print_branch (max_level, level + 1, nd->left);
	}
	if (nd->right)
	{
		printf ("R");
		print_branch (max_level, level + 1, nd->right);
	}
}

void Tree::error_handler (int er_code)
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
			printf ("Unknown error (Tree::error_handler())\n");
	}
}
