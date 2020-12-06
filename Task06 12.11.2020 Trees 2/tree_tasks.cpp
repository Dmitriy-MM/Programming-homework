#include "tree.h"

int Tree::get_count_elems (Tree_node * pos, int k)
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
int Tree::get_length (Tree_node * pos)
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


//Возвращает количество поддеревьев у которых не более k вершин.
int Tree::task01 (int k, Tree_node * pos)
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
		res = 1;
	
	if (pos->left != nullptr)
		res += task01 (k, pos->left);
	if (pos->right != nullptr)
		res += task01 (k, pos->right);
	return res;
}

//Возвращает количество элементов в поддеревьях у которых не более k вершин.
int Tree::task02 (int k, Tree_node * pos)
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
		res += task02 (k, pos->left);
	if (pos->right != nullptr)
		res += task02 (k, pos->right);
	return res;
}

//Возвращает количество поддеревьев у которых не более k уровней.
int Tree::task03 (int k, Tree_node * pos)
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
		res = 1;
	
	if (pos->left != nullptr)
		res += task03 (k, pos->left);
	if (pos->right != nullptr)
		res += task03 (k, pos->right);
	return res;
}


//Возвращает количество поддеревьев у которых не более k элементов в любом уровне.
int Tree::task04 (int k, Tree_node * pos)
{
	int cur, i, res = 0;
	
	if (pos == nullptr)
	{
		if (root == nullptr)
			return 0;
		else
			pos = root;
	}
	
	i = 0;
	cur = task05 (i, pos);
	while (cur != 0)
	{
		if (cur > k)
			break;
		
		i++;
		cur = task05 (i, pos);
	}
	
	if (cur == 0)
	{
		res = 1;
	}
	
	if (pos->left != nullptr)
		res += task04 (k, pos->left);
	if (pos->right != nullptr)
		res += task04 (k, pos->right);
	
	return res;
}


//Возвращает количество элементов в k-ом уровне.
int Tree::task05 (int level_to_go, Tree_node * pos)
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
		result += task05 (level_to_go-1, pos->left);
	if (pos->right != nullptr)
		result += task05 (level_to_go-1, pos->right);
	
	return result;
	
}



