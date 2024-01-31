#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *nnode = NULL, *parnode = NULL;

	if (tree)
	{
		parnode = *tree;
		if (!*tree)
		{
			nnode = binary_tree_node(*tree, value);
			*tree = nnode;
		}
		else
		{
			while (parnode)
			{
				if ((parnode->n > value) && (parnode->left))
				{
					parnode = parnode->left;
				}
				else if ((parnode->n < value) && (parnode->right))
				{
					parnode = parnode->right;
				}
				else
					break;
			}
			if (parnode->n < value)
			{
				nnode = binary_tree_node(parnode, value);
				parnode->right = nnode;
			}
			else if (parnode->n > value)
			{
				nnode = binary_tree_node(parnode, value);
				parnode->left = nnode;
			}
		}
	}
	return (nnode);
}
