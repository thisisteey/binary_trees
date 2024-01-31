#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *origrt, *newrt, *newrgtrt;

	if (!tree)
		return (NULL);
	origrt = tree;
	newrt = origrt->right;
	if (newrt)
	{
		newrt->parent = origrt->parent;
		newrgtrt = newrt->left;
		newrt->left = origrt;
		if (origrt->parent)
		{
			if (origrt->parent->left == origrt)
				origrt->parent->left = newrt;
			if (origrt->parent->right == origrt)
				origrt->parent->right = newrt;
		}
		origrt->right = newrgtrt;
		origrt->parent = newrt;
		if (newrgtrt)
		{
			newrgtrt->parent = origrt;
		}
	}
	return (newrt);
}
