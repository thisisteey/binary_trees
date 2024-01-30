#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: tree balance factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lfhgt = 0, rthgt = 0;

		lfhgt = (tree->left) ? binary_tree_height(tree->left) + 1 : 1;
		rthgt = (tree->right) ? binary_tree_height(tree->right) + 1 : 1;
		return (lfhgt > rthgt ? lfhgt : rthgt);
	}
	return (0);
}
