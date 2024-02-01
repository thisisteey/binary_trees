#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * bt_maxvalue - checks each node of a binary tree is at maximum value
 * @root: pointer to the root node of the binary tree
 * Return: 1 if all nodes are at maximum value or 0 if not
 */
int bt_maxvalue(const binary_tree_t *root)
{
	int ltnode = 1, rtnode = 1;

	if (!root)
		return (0);
	if (!root->left && !root->right)
		return (1);
	if (root->left)
	{
		if (root->n <= root->left->n)
			return (0);
		ltnode = bt_maxvalue(root->left);
	}
	if (root->right)
	{
		if (root->n <= root->right->n)
			return (0);
		rtnode = bt_maxvalue(root->right);
	}
	return (ltnode && rtnode);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int compres;

	if (!tree)
		return (0);
	compres = binary_tree_is_complete(tree);
	if (!compres)
		return (0);
	return (bt_maxvalue(tree));
}
