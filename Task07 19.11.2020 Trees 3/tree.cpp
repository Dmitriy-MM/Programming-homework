#include "tree.h"

void Tree::add_node (Tree_node * nd, Tree_node * where)
{
	if (where == nullptr) where = root;
	
	if (root->down == nullptr)
	{
		root->down = nd;
	}
	else if (*nd < *where)
	{
		if (where->down == nullptr)
			where->down = nd;
		else
		{
			//add_node (nd, where->down);
			if (*(where->down) >= *where)
			{
				nd->level = where->down;
				where->down = nd;
			}
			else
			{
				add_node (nd, where->down);
			}
		}
	}
	else if (*nd > *where)
	{
		Tree_node * curr = nullptr;
		
		for (curr = where->down; (curr != nullptr) && (curr->level != nullptr); curr = curr->level)
		{
			;
		}
		if (curr == nullptr)//Значит where->down было Nullptr.
			where->down = nd;
		else if (*curr <= *where)
			curr->level = nd;
		else
			add_node (nd, curr);
	}
	else
	{
		if (where->down == nullptr)
			where->down = nd;
		else
		{
			Tree_node * tmp = nullptr;
			
			//Если *nd <= *down, то добавить в начало, иначе в следующий от первого.
			if (*nd <= *(where->down))
			{
				tmp = where->down;
				where->down = nd;
				nd->level = tmp;
			}
			else
			{
				where = where->down;
				tmp = where->level;
				where->level = nd;
				nd->level = tmp;
			}
		}
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
	Tree_node * curr = nullptr;
	int i, k;
	
	if (max_level <= level) return;
	
	
	for (curr = nd, k = 0; curr != nullptr; curr = curr->level, k++)
	{
		for (i = 0; i < level-1; i++)
			printf (" |");
		if (i < level)
			printf (" ");
		printf ("%d) ", k);
		curr->print ();
		printf ("\n");
		if (curr->down != nullptr)
			print_branch (max_level, level + 1, curr->down);
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

void Tree::destroy_tree (Tree_node * nd)
{
	Tree_node * curr = nullptr, *level = nullptr, * down = nullptr;
	
	
	for (curr = nd; curr != nullptr; curr = level)
	{
		down = curr->down;
		level = curr->level;
		delete curr;
		if (down != nullptr)
		{
			destroy_tree (down);
		}
	}
}

Tree::~Tree ()
{
	if (root != nullptr)
		destroy_tree (root);
	root = nullptr;
}




