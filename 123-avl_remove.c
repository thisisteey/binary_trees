#include "binary_trees.h"

/**
 * bst_inorder_successor - finds the minimum value of a Binary Search Tree
 * @root: pointer to the root node of the Binary Search Tree
 * Return: pointer to the node with the minimum value
 */
static bst_t *bst_inorder_successor(bst_t *root)
{
	if (!root)
	{
		return (NULL);
	}
	if (!root->left)
	{
		return (root);
	}
	return (bst_inorder_successor(root->left));
}

/**
 * bst_delete_node - deletes a given value from a BST
 * @tree: double pointer to the tree root node to be deleted
 * @value: value of the node to be deleted
 * Return: pointer to the new root node after deletion
 */
static bst_t *bst_delete_node(bst_t **tree, int value)
{
	bst_t *curr = *tree, *ptnd = NULL, **plnk, *nnode, *rsrc = NULL;

	while (curr)
	{
		if (curr->n == value)
		{
			ptnd = curr->parent, rsrc = ptnd;
			plnk = !ptnd ? tree : ptnd->n > curr->n ? &ptnd->left : &ptnd->right;
			if (!curr->right && !curr->left)
				*plnk = NULL;
			else if (!curr->right)
				*plnk = curr->left, curr->left->parent = curr->parent;
			else if (!curr->left)
				*plnk = curr->right, curr->right->parent = curr->parent;
			else
			{
				nnode = bst_inorder_successor(curr->right);
				if (nnode == curr->right)
					*plnk = nnode, nnode->parent = curr->parent,
					rsrc = curr->parent, nnode->left = curr->left,
					nnode->left->parent = nnode;
				else
				{
					nnode->parent->left = nnode->right, rsrc = nnode->parent;
					if (nnode->right)
						nnode->right->parent = nnode->parent;
					*plnk = nnode, nnode->parent = ptnd, nnode->left = curr->left;
					if (nnode->left)
						nnode->left->parent = nnode;
					nnode->right = curr->right;
					if (nnode->right)
						nnode->right->parent = nnode;
				}
			}
			free(curr);
			break;
		}
		curr = value > curr->n ? curr->right : curr->left;
	}
	return (rsrc);
}

/**
 * avl_rebalance - rebalance an AVL tree by rotating the unbalanced subtree
 * @tree: double pointer to the root node of the AVL tree
 * @insnd: pointer to the newly inserted node
 * Return: void
 */
void avl_rebalance(avl_t **tree, avl_t *insnd)
{
	avl_t *currnd = insnd, *newtree = *tree;
	int balfctr = 0;

	while (currnd)
	{
		balfctr = binary_tree_balance(currnd);
		if (!((balfctr >= -1) && (balfctr <= 1)))
		{
			if ((balfctr == 2) && ((binary_tree_balance(currnd->left) == 1)
				|| (binary_tree_balance(currnd->left) == 0)))
			{
				newtree = binary_tree_rotate_right(currnd);
			}
			else if ((balfctr == 2) && (binary_tree_balance(currnd->left) == -1))
			{
				currnd->left = binary_tree_rotate_left(currnd->left);
				newtree = binary_tree_rotate_right(currnd);
			}
			else if ((balfctr == -2) && ((binary_tree_balance(currnd->right) == -1)
				|| (binary_tree_balance(currnd->right) == 0)))
			{
				newtree = binary_tree_rotate_left(currnd);
			}
			else if ((balfctr == 2) && (binary_tree_balance(currnd->left) == -1))
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
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *newrt = root, *parnode = NULL;

	if (newrt)
	{
		parnode = bst_delete_node(&newrt, value);
		avl_rebalance(&newrt, parnode);
	}
	return (newrt);
}
