#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tgtnd = NULL;

	if (tree)
	{
		if (tree->left)
		{
			tgtnd = tree->left->parent;
		}
		if (!tgtnd && tree->right)
		{
			tgtnd = tree->right->parent;
		}
		while (tgtnd)
		{
			if (tgtnd->n < value)
			{
				tgtnd = tgtnd->right;
			}
			else if (tgtnd->n > value)
			{
				tgtnd = tgtnd->left;
			}
			else
				break;
		}
	}
	return (tgtnd);
}
