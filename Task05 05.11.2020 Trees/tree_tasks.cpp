#include "tree.h"


//Возвращает количество концевых элементов дерева.
int Tree::task01 (Tree_node * pos)
{
	int res = 0;
	
	if (pos == nullptr)
	{
		if (root == nullptr)
			return 0;
		else
			pos = root;
	}
	if (pos->left != nullptr)
		res += task01 (pos->left);
	if (pos->right != nullptr)
		res += task01 (pos->right);
	
	if (res == 0) //Нету потомков - значит этот элемент сам есть концевой.
		return 1;
	else
		return res;
}

//Возвращает длину самой большой ветки дерева.
int Tree::task02 (Tree_node * pos)
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
		second_res = 1 + task02 (pos->left);
		res = second_res > res? second_res: res;
	}
	if (pos->right != nullptr)
	{
		second_res = 1 + task02 (pos->right);
		res = second_res > res? second_res: res;
	}
	return res;
}

//Возвращает количество элементов на уровне дерева который подан, если до него возможно дойти.
int Tree::task03_second (Tree_node * pos, int level_to_go)
{
	int result = 0;
	
	if (pos == nullptr)
		return 0;
	if (level_to_go == 0)
		return 1;
	
	if (pos->left != nullptr)
		result += task03_second (pos->left, level_to_go-1);
	if (pos->right != nullptr)
		result += task03_second (pos->right, level_to_go-1);
	
	return result;
}

//Возвращает максимальное количество элементов в одном уровне дерева.
int Tree::task03 (Tree_node * pos)
{
	int cur, max = -1, i;
	
	if (pos == nullptr)
	{
		if (root == nullptr)
			return 0;
		else
			pos = root;
	}
	
	i = 0;
	while ((cur = task03_second (root, i)) != 0)
	{
		i++;
		if (cur > max)
			max = cur;
	}
	return max;
}


//Возвращает максимальную разность между между глубинами левого и правого поддеревьев в узлах дерева.
int Tree::task04 (Tree_node * pos)
{
	int result, second_res;
	int left_deep = 0, right_deep = 0;
	
	if (pos == nullptr)
	{
		if (root == nullptr)
			return 0;
		else
			pos = root;
	}
	
	if (pos->left != nullptr)
		left_deep = task02 (pos->left);
	if (pos->right != nullptr)
		right_deep = task02 (pos->right);
	
	//Модуль разности left_deep и right_deep.
	result = (left_deep > right_deep)? left_deep - right_deep: right_deep - left_deep;
	
	if (pos->left != nullptr)
	{
		second_res = task04 (pos->left);
		result = (result > second_res)? result: second_res;
	}
	if (pos->right != nullptr)
	{
		second_res = task04 (pos->right);
		result = (result > second_res)? result: second_res;
	}
	
	return result;
}


//Возвращает количество элементов имеющих ровно одного потомка.
int Tree::task05 (Tree_node * pos)
{
	int result = 0;
	int is_right_exist, is_left_exist;
	
	if (pos == nullptr)
	{
		if (root == nullptr)
			return 0;
		else
			pos = root;
	}
	
	is_left_exist = (pos->left != nullptr);
	is_right_exist = (pos->right != nullptr);
	
	//Есть только один потомок.
	if (
		((is_left_exist && is_right_exist) == 0) &&
		((is_left_exist || is_right_exist) == 1)
	)
		result++;
	if (is_left_exist)
		result += task05 (pos->left);
	if (is_right_exist)
		result += task05 (pos->right);
	
	return result;
}