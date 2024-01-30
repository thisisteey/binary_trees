#include "binary_trees.h"

/**
 * binary_tree_stats - calculates the statistics of a binary tree
 * @tree: pointer to the binary tree to be calculated
 * @pathlen: total height of the current path in the binary tree
 * @lvsval: pointer to the binary tree's leaf count value
 * @max_ht: pointer to the binary tree's maximum height value
 * Return: void
 */
void binary_tree_stats(const binary_tree_t *tree, size_t pathlen,
		size_t *lvsval, size_t *max_ht)
{
	if (tree)
	{
		if (!tree->left && !tree->right)
		{
			if (lvsval)
			{
				(*lvsval)++;
			}
			if (max_ht && (pathlen > *max_ht))
			{
				*max_ht = pathlen;
			}
		}
		else
		{
			binary_tree_stats(tree->left, pathlen + 1, lvsval, max_ht);
			binary_tree_stats(tree->right, pathlen + 1, lvsval, max_ht);
		}
	}
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL or 1 if tree is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t lvsct = 0, treeht = 0;

	binary_tree_stats(tree, 0, &lvsct, &treeht);
	return ((int)lvsct == (1 << treeht));
}
