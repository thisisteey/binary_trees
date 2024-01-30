#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0 if node is NULL or not a leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int leafnode = 0;

	if (node)
	{
		leafnode = (node->left == NULL && node->right == NULL);
	}
	return (leafnode);
}
