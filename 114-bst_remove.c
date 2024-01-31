#include "binary_trees.h"

/**
 * bst_inorder_successor - finds the minimum value of a Binary Search Tree
 * @root: pointer to the root node of the Binary Search Tree
 * Return: pointer to the node with the minimum value
 */
bst_t *bst_inorder_successor(bst_t *root)
{
	while (root->left)
	{
		root = root->left;
	}
	return (root);
}

/**
 * bst_delete_node - deletes a given node from a BST
 * @root: pointer to the root node of the Binary Search Tree
 * @tgtnd: pointer to the target node to delete from the Binary Search Tree
 * Return: pointer to the new root node after deletion
 */
bst_t *bst_delete_node(bst_t *root, bst_t *tgtnd)
{
	bst_t *parnode = tgtnd->parent, *succnd = NULL;

	if (!tgtnd->left)
	{
		if (parnode && parnode->left == tgtnd)
		{
			parnode->left = tgtnd->right;
		}
		else if (parnode)
		{
			parnode->right = tgtnd->right;
		}
		if (tgtnd->right)
		{
			tgtnd->right->parent = parnode;
		}
		free(tgtnd);
		return (!parnode ? tgtnd->right : root);
	}
	if (!tgtnd->right)
	{
		if (parnode && parnode->left == tgtnd)
		{
			parnode->left = tgtnd->left;
		}
		else if (parnode)
		{
			parnode->right = tgtnd->left;
		}
		if (tgtnd->left)
		{
			tgtnd->left->parent = parnode;
		}
		free(tgtnd);
		return (!parnode ? tgtnd->left : root);
	}
	succnd = bst_inorder_successor(tgtnd->right);
	tgtnd->n = succnd->n;
	return (bst_delete_node(root, succnd));
}

/**
 * bst_remove_node_iter - iteratively remove a node from a Binary Search Tree
 * @root: pointer to the root node of the Binary Search Tree
 * @currnd: pointer to the current node in the Binary Search Tree
 * @value: value to rmeove from the Binary Search Tree
 * Return: pointer to the new root node after removal
 */
bst_t *bst_remove_node_iter(bst_t *root, bst_t *currnd, int value)
{
	if (currnd)
	{
		if (currnd->n == value)
		{
			return (bst_delete_node(root, currnd));
		}
		if (currnd->n > value)
		{
			return (bst_remove_node_iter(root, currnd->left, value));
		}
		return (bst_remove_node_iter(root, currnd->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_node_iter(root, root, value));
}
