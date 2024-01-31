#include "binary_trees.h"

/**
 * balance_node_check - checks the node balance of the tree after insertion
 * @tree: double pointer to the current node in the tree
 * @value: value of the node to be inserted
 * Return: void
 */
void balance_node_check(avl_t **tree, int value)
{
	int balfctr = binary_tree_balance(*tree);

	if (balfctr > 1 && value < (*tree)->left->n)
	{
		*tree = binary_tree_rotate_right(*tree);
		return;
	}
	if (balfctr < -1 && value > (*tree)->right->n)
	{
		*tree = binary_tree_rotate_left(*tree);
		return;
	}
	if (balfctr > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
		return;
	}
	if (balfctr < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
		return;
	}
}

/**
 * avl_insert_check - checks if the given node is inserted into avl tree
 * @tree: double pointer to the root node of the tree
 * @value: value to be inserted into the avl tree
 * Return: pointer to the inserted new node
 */
avl_t *avl_insert_check(avl_t **tree, int value)
{
	avl_t *nnode;

	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			nnode = avl_insert_check(&((*tree)->left), value);
			if (nnode)
			{
				balance_node_check(tree, value);
			}
			return (nnode);
		}
	}
	if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
		{
			nnode = avl_insert_check(&((*tree)->right), value);
			if (nnode)
			{
				balance_node_check(tree, value);
			}
			return (nnode);
		}
	}
	return (NULL);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *nnode;

	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	nnode = avl_insert_check(tree, value);
	return (nnode);
}
