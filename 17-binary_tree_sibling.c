#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *ltnode = NULL;
	binary_tree_t *rtnode = NULL;

	if (node && node->parent)
	{
		ltnode = node->parent->left;
		rtnode = node->parent->right;
	}
	return (ltnode == node ? rtnode : ltnode);
}
