#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node that is created
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *nnode;

	if (!parent)
		return (NULL);
	nnode = binary_tree_node(parent, value);
	if (!nnode)
		return (NULL);
	if (parent->left)
	{
		nnode->left = parent->left;
		parent->left->parent = nnode;
	}
	parent->left = nnode;
	return (nnode);
}
