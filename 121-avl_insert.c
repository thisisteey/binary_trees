#include "binary_trees.h"

/**
 * bst_insert_node - adds a node to a Binary Search Tree
 * @tree: double pointer to the Binary Search Tree
 * @value: value to be added to the new node of the BST
 * Return: pointer to the new node or NULL if it fails
 */
bst_t *bst_insert_node(bst_t **tree, int value)
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
				if (parnode->n > value && parnode->left)
					parnode = parnode->left;
				else if (parnode->n < value && parnode->right)
					parnode = parnode->right;
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

/**
 * bt_height - calculates the height of a binary tree
 * @tree: pointer to the binary tree
 * Return: the height of the binary tree
 */
int bt_height(const binary_tree_t *tree)
{
	int lthgt = 0, rthgt = 0;

	if (tree)
	{
		lthgt = bt_height(tree->left);
		rthgt = bt_height(tree->right);
	}
	return ((lthgt > rthgt ? lthgt : rthgt) + 1);
}

/**
 * avl_balance - rebalance an AVL tree by rotating the unbalanced subtree
 * @tree: double pointer to the root node of the AVL tree
 * @insnd: pointer to the newly inserted node
 * Return: void
 */
void avl_balance(avl_t **tree, avl_t *insnd)
{
	avl_t *currnd = insnd, *newtree = *tree;
	int lthgt = 0, rthgt = 0, balfctr = 0;

	while (currnd)
	{
		lthgt = bt_height(currnd->left);
		rthgt = bt_height(currnd->right);
		balfctr = lthgt - rthgt;
		if (!((balfctr >= -1) && (balfctr <= 1)))
		{
			if ((balfctr == 2) && (insnd->n < currnd->left->n))
			{
				newtree = binary_tree_rotate_right(currnd);
			}
			else if ((balfctr == 2) && (insnd->n > currnd->left->n))
			{
				currnd->left = binary_tree_rotate_left(currnd->left);
				newtree = binary_tree_rotate_right(currnd);
			}
			else if ((balfctr == -2) && (insnd->n > currnd->right->n))
			{
				newtree = binary_tree_rotate_left(currnd);
			}
			else if ((balfctr == -2) && (insnd->n < currnd->right->n))
			{
				currnd->right = binary_tree_rotate_right(currnd->right);
				newtree = binary_tree_rotate_left(currnd);
			}
			newtree = (currnd == *tree ? newtree : *tree);
			break;
		}
		currnd = currnd->parent;
	}
	*tree = newtree;
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *nnode = NULL;

	if (tree)
	{
		nnode = bst_insert_node(tree, value);
		avl_balance(tree, nnode);
	}
	return (nnode);
}
