#include "binary_trees.h"
#include "11-binary_tree_size.c"

/**
 * tree_comp - checks if a tree is complete
 * @tree: pointer to the root of the tree to be checked
 * @ndidx: index for the right and left node
 * @treesz: the size of the tree to be checked
 * Return: 1 if tree is complete or 0 otherwise
 */
int tree_comp(const binary_tree_t *tree, int ndidx, int treesz)
{
	if (!tree)
	{
		return (1);
	}
	if (ndidx >= treesz)
	{
		return (0);
	}
	return (tree_comp(tree->left, 2 * ndidx + 1, treesz) &&
			tree_comp(tree->right, 2 * ndidx + 2, treesz));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 0 iif tree is NULL, otherwise 1
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int treesz = binary_tree_size(tree);
	int ndidx = 0;

	if (!tree)
	{
		return (0);
	}
	return (tree_comp(tree, ndidx, treesz));
}
