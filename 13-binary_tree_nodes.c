#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: nodes with at least 1 child or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t ndsct = 0;

	if (tree)
	{
		ndsct += (tree->left || tree->right);
		ndsct += binary_tree_nodes(tree->left);
		ndsct += binary_tree_nodes(tree->right);
	}
	return (ndsct);
}
