#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nnode = NULL;

	if (parent)
	{
		nnode = malloc(sizeof(binary_tree_t));
		if (nnode)
		{
			nnode->left = NULL;
			nnode->right = parent->right;
			nnode->parent = parent;
			nnode->n = value;
			if (parent->right)
			{
				parent->right->parent = nnode;
			}
			parent->right = nnode;
		}
	}
	return (nnode);
}
