#include "binary_trees.h"

/**
 * balance_tree - balance the AVL tree
 * @tree: pointer to the root node of the tree to balance
 * Return: pointer to the new root node of the tree once balanced
 */
avl_t *balance_tree(avl_t *tree)
{
	int balance;

	if (!tree)
		return (NULL);

	balance = binary_tree_balance(tree);

	/* Left Heavy */
	if (balance > 1)
	{
		if (binary_tree_balance(tree->left) >= 0)
			return binary_tree_rotate_right(tree);
		else
		{
			tree->left = binary_tree_rotate_left(tree->left);
			return binary_tree_rotate_right(tree);
		}
	}

	/* Right Heavy */
	if (balance < -1)
	{
		if (binary_tree_balance(tree->right) <= 0)
			return binary_tree_rotate_left(tree);
		else
		{
			tree->right = binary_tree_rotate_right(tree->right);
			return binary_tree_rotate_left(tree);
		}
	}

	return tree;
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (!(*tree))
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&((*tree)->left), value);
		if ((*tree)->left)
			(*tree)->left->parent = *tree;
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&((*tree)->right), value);
		if ((*tree)->right)
			(*tree)->right->parent = *tree;
	}
	else
		return (NULL); /* Duplicates are not allowed in AVL trees */

	/* Update height and balance factor of the current node */
	/*(*tree)->parent = NULL; Reset parent for recursion */
	*tree = balance_tree(*tree);

	return (*tree);
}
