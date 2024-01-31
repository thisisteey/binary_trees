#include "binary_trees.h"

/**
 * avl_balfctr - calculates the balance factor of a AVL tree
 * @tree: double pointer to the tree to calculate
 * Return: void
 */
void avl_balfctr(avl_t **tree)
{
	int balval;

	if (!tree || !*tree)
		return;
	if (!(*tree)->left && !(*tree)->right)
		return;
	avl_balfctr(&(*tree)->left);
	avl_balfctr(&(*tree)->right);
	balval = binary_tree_balance((const binary_tree_t *)*tree);
	if (balval > 1)
	{
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	}
	else if (balval < -1)
	{
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
	}
}

/**
 * inorder_successor - finds the minimum value of a Binary Search Tree
 * @root: pointer to the root node of the Binary Search Tree
 * Return: the node with the minimum value
 */
int inorder_successor(bst_t *root)
{
	int ltmin = 0;

	if (!root)
	{
		return (0);
	}
	else
	{
		ltmin = inorder_successor(root->left);
		if (ltmin == 0)
		{
			return (root->n);
		}
		return (ltmin);
	}
}

/**
 * remove_node_type - deletes a node based on its children
 * @node: pointer to the node to be removed
 * Return: the new value of the node or 0 if it has no child
 */
int remove_node_type(bst_t *node)
{
	int newval = 0;

	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left))
	{
		if (!node->left)
		{
			if (node->parent->right == node)
				node->parent->right = node->right;
			else
				node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		if (!node->right)
		{
			if (node->parent->right == node)
				node->parent->right = node->left;
			else
				node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		free(node);
		return (0);
	}
	else
	{
		newval = inorder_successor(node->right);
		node->n = newval;
		return (newval);
	}
}

/**
 * bst_remove_node - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removal
 */
bst_t *bst_remove_node(bst_t *root, int value)
{
	int nodetype = 0;

	if (!root)
		return (NULL);
	if (value < root->n)
		bst_remove_node(root->left, value);
	else if (value > root->n)
		bst_remove_node(root->right, value);
	else if (value == root->n)
	{
		nodetype = remove_node_type(root);
		if (nodetype != 0)
			bst_remove_node(root->right, nodetype);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *aftrt = (avl_t *) bst_remove_node((bst_t *) root, value);

	if (!aftrt)
		return (NULL);
	avl_balfctr(&aftrt);
	return (aftrt);
}
