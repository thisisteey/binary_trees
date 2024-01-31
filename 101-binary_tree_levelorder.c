#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * print_node_level - prints the binary tree nodes by level
 * @node: pointer to the binary tree node
 * @func: pointer to a function to call for each node
 * @treelvl: the current level of the binary tree
 * Return: void
 */
void print_node_level(binary_tree_t *node, void (*func)(int), int treelvl)
{
	if (node && func)
	{
		if (treelvl == 1)
			func(node->n);
		if (treelvl > 1)
		{
			print_node_level(node->left, func, treelvl - 1);
			print_node_level(node->right, func, treelvl - 1);
		}
	}
}

/**
 * binary_tree_levelorder - goes through a tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t tree_ht = 0, currlvl;
	binary_tree_t *treecpy = (binary_tree_t *)tree;

	if (!tree || !func)
		return;
	tree_ht = binary_tree_height(tree);
	for (currlvl = 0 ; currlvl <= tree_ht + 1 ; currlvl++)
		print_node_level(treecpy, func, currlvl);
}
