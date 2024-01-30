#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent node of the new binary tree node to be created
 * @value: value to put in the new node to be created
 * Return: pointer to the new node, or NULL on code failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nnode = malloc(sizeof(binary_tree_t));

	if (nnode)
	{
		nnode->left = NULL;
		nnode->right = NULL;
		nnode->parent = parent;
		nnode->n = value;
	}
	return (nnode);
}
