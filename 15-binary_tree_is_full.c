#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int rtct, ltct;

	rtct = ltct = 0;
	if (!tree || !tree->left != !tree->right)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	ltct = binary_tree_is_full(tree->left);
	rtct = binary_tree_is_full(tree->right);
	if (rtct && ltct)
		return (1);
	return (0);
}
