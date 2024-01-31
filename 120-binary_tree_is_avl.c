#include "binary_trees.h"

/**
 * binary_bst_check - checks if a binary tree is a Binary Search Tree
 * @tree: pointer to the binary tree
 * @minval: minimum value allowed for the binary tree
 * @maxval: maximum value allowed for the binary tree
 * @vldbst: pointer to the validation flag value of the tree
 * Return: void
 */
void binary_bst_check(const binary_tree_t *tree, int minval, int maxval,
		int *vldbst)
{
	if (tree)
	{
		if ((tree->n > minval) && (tree->n < maxval))
		{
			binary_bst_check(tree->left, minval, tree->n, vldbst);
			binary_bst_check(tree->right, tree->n, maxval, vldbst);
		}
		else
		{
			if (vldbst)
			{
				*vldbst = 0;
			}
		}
	}
}

/**
 * bt_height - calculates the height of a binary tree
 * @tree: pointer to the binary tree
 * @currht: the current height of the binary tree
 * @maxht: pointer to the maximum height of the binary tree
 * Return: void
 */
void bt_height(const binary_tree_t *tree, int currht, int *maxht)
{
	if (tree)
	{
		if (!tree->left && !tree->right)
		{
			if (currht > *maxht)
			{
				*maxht = currht;
			}
		}
		else
		{
			bt_height(tree->left, currht + 1, maxht);
			bt_height(tree->right, currht + 1, maxht);
		}
	}
}

/**
 * bt_balance - checks the balance of a binary tree
 * @tree: pointer to the binary tree
 * @vldbal: pointer to the balanced tree flag value
 * Return: void
 */
void bt_balance(const binary_tree_t *tree, int *vldbal)
{
	int balfctr = 0, lthgt = 0, rthgt = 0;

	if (tree)
	{
		bt_height(tree->left, 1, &lthgt);
		bt_height(tree->right, 1, &rthgt);
		balfctr = lthgt - rthgt;
		if (balfctr < -1 || balfctr > 1)
		{
			if (vldbal)
			{
				*vldbal = 0;
			}
		}
		else
		{
			bt_balance(tree->left, vldbal);
			bt_balance(tree->right, vldbal);
		}
	}
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int vldbst = 0, vldavl = 0;

	if (tree)
	{
		vldbst = 1;
		binary_bst_check(tree, INT_MIN, INT_MAX, &vldbst);
		if (vldbst == 1)
		{
			vldavl = 1;
			bt_balance(tree, &vldavl);
		}
	}
	return (vldavl);
}
