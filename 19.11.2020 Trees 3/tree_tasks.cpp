#include "tree.h"

//Возврщает количество потомков данного узла.
int Tree::count_descendants (Tree_node * pos)
{
	Tree_node * curr = nullptr;
	int result = 0;
	
	if (pos->down == nullptr)
		return 0;
	
	pos = pos->down;
	for (curr = pos; curr != nullptr; curr = curr->level)
	{
		result++;
		if (curr->down != nullptr)
			result += count_descendants (curr);
	}
	
	return result;
}

//Возврщает количество уровней поддерева, образованного данным узлом.
int Tree::get_max_deep (Tree_node * pos)
{
	Tree_node * curr = nullptr;
	int deep = 1, max_deep = 1, deep_down;
	
	if (pos == nullptr)
		return 0;
	
	pos = pos->down;
	for (curr = pos; curr != nullptr; curr = curr->level)
	{
	//	if (curr->down != nullptr)
	//	{
	//		int deep_down = get_max_deep (curr->down);
	//		deep += deep_down;
	//		if (deep > max_deep)
	//			max_deep = deep;
	//		deep -= deep_down;
	//	}
		deep_down = get_max_deep (curr);
		deep += deep_down;
		if (deep > max_deep)
			max_deep = deep;
		deep -= deep_down;
	}
	
	return max_deep;
}


//Возврщает количество элементов на n-ом уровне,
//если до него можно дойти.
int Tree::count_elems_in_level (Tree_node * pos, int lvl_to_go)
{
	Tree_node * curr = nullptr;
	int result = 0;
	
	if (lvl_to_go == 0)
		return 1;
	
	if (pos == nullptr)
		return 0;
	if (pos->down == 0)
		return 0;
	pos = pos->down;
	for (curr = pos; curr != nullptr; curr = curr->level)
	{
		result += count_elems_in_level (curr, lvl_to_go-1);
	}
	
	return result;
}

//Возврщает количество элементов в узлах,
//имеющих ровно k потомков.
int Tree::task01 (int k, Tree_node * pos)
{
	Tree_node * curr = nullptr;
	int result = 0, count_of_descendants;
	
	if (pos == nullptr)
		pos = root;
	for (curr = pos; curr != nullptr; curr = curr->level)
	{
		count_of_descendants = count_descendants (curr);
		if (count_of_descendants == k)
			result++;
		// printf ("count_of_descendants %d\n", count_of_descendants);
		if (curr->down != nullptr)
		{
			result += task01 (k, curr->down);
		}
	}
	
	return result;
}
#if 0
int Tree::task01 (int k, Tree_node * pos)
{
	Tree_node * curr = nullptr;
	int result = 0, count_of_descendants;
	
	if (pos == nullptr)
		pos = root;
	for (curr = pos; curr != nullptr; curr = curr->level)
	{
		count_of_descendants = count_descendants (curr);
		if (count_of_descendants == k)
			result++;
		if (curr->down != nullptr)
		{
			result += task01 (k, curr->down);
		}
	}
	
	return result;
}
#endif

//Возврщает количество элементов в поддеревьях,
//имеющих не более k вершин.
int Tree::task02 (int k, Tree_node * pos)
{
	Tree_node * curr = nullptr;
	int result = 0, count_of_descendants;
	
	if (pos == nullptr)
		pos = root;
	for (curr = pos; curr != nullptr; curr = curr->level)
	{
		count_of_descendants = count_descendants (curr);
		if (count_of_descendants + 1 <= k)
			result += count_of_descendants + 1;
		if (curr->down != nullptr)
		{
			result += task02 (k, curr->down);
		}
	}
	
	return result;
}


//Возврщает количество элементов в поддеревьях,
//имеющих не более k уровней.
int Tree::task03 (int k, Tree_node * pos)
{
	Tree_node * curr = nullptr;
	int result = 0, deep;
	
	if (pos == nullptr)
		pos = root;
	for (curr = pos; curr != nullptr; curr = curr->level)
	{
		deep = get_max_deep (curr);
		// printf ("deep %d\n", deep);
		if (deep <= k)
		{
			result += count_descendants (curr) + 1;
		}
		if (curr->down != nullptr)
		{
			result += task03 (k, curr->down);
		}
	}
	
	return result;
}


//Возврщает количество элементов в поддеревьях,
//имеющих не более k узлов в любом уровне.
int Tree::task04 (int k, Tree_node * pos)
{
	Tree_node * curr = nullptr;
	int result = 0, second_res;
	int i, do_count, count_of_descendants;
	
	if (pos == nullptr)
		pos = root;
	for (curr = pos; curr != nullptr; curr = curr->level)
	{
		//do_count - дерево имеет не более k узлов  в любом уровне (считать ли этот элемент).
		i = 0, do_count = 1, count_of_descendants = 0;
		while ((second_res = count_elems_in_level (curr, i)) > 0)
		{
			count_of_descendants += second_res;
			if (second_res > k)
			{
				do_count = 0;
				break;
			}
			i++;
		}
		if (do_count)
			result += count_of_descendants;
		
		if (curr->down != nullptr)
		{
			result += task04 (k, curr->down);
		}
	}
	
	return result;
}

//Возврщает количество элементов в k-ом уровне дерева.
int Tree::task05 (int k)
{
	return count_elems_in_level (root, k);
}

//Возврщает количество элементов во всех ветвях,
//длины не менее k считая от корня до листа.
int Tree::task06 (int k, Tree_node * pos, int curr_lvl)
{
	Tree_node * curr = nullptr;
	int result = 0;
	
	if (pos == nullptr)
		pos = root;
	for (curr = pos; curr != nullptr; curr = curr->level)
	{
		if (curr->down == nullptr)
		{
			if (curr_lvl+1 >= k)
				result += curr_lvl+1;
		}
		else
		{
			result += task06 (k, curr->down, curr_lvl+1);
		}
	}
	
	return result;
}
