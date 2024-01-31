#include "binary_trees.h"

/**
 * binary_tree_value- checks the allowable values of a binary tree
 * @node: pointer to the node of the binary tree
 * @minval: the minimum allowable value
 * @maxval: the maximum allowable value
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_value(const binary_tree_t *node, int minval, int maxval)
{
	if (!node)
		return (1);
	if (node->n < minval || node->n > maxval)
	{
		return (0);
	}
	return (binary_tree_value(node->left, minval, node->n - 1) &&
			binary_tree_value(node->right, node->n + 1, maxval));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}
	return (binary_tree_value(tree, INT_MIN, INT_MAX));
}
