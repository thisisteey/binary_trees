#include "binary_trees.h"

/**
 * bt_height - calculate the height of a binary tree
 * @root: pointer to the root node of the binary tree
 * Return: binary tree height or 0 if tree is empty
 */
size_t bt_height(const heap_t *root)
{
	size_t lthgt = 0, rthgt = 0;

	if (!root)
		return (0);
	if (root->left)
		lthgt = 1 + bt_height(root->left);
	if (root->right)
		rthgt = 1 + bt_height(root->right);
	if (lthgt > rthgt)
		return (lthgt);
	return (rthgt);
}

/**
 * bt_height_sum - calculates the sum of heights of a binary tree
 * @root: pointer to the root node of the binary tree
 * Return: sum of binary tree heights or 0 if tree is empty
 */
size_t bt_height_sum(const binary_tree_t *root)
{
	size_t lthgt = 0, rthgt = 0;

	if (!root)
		return (0);
	if (root->left)
		lthgt = 1 + bt_height_sum(root->left);
	if (root->right)
		rthgt = 1 + bt_height_sum(root->right);
	return (lthgt + rthgt);
}

/**
 * trav_preorder - navigates through a binary tree using pre-order traversal
 * @strnd: pointer to the starting node of the binary tree to navigate
 * @lstnd: double pointer to the ending node in the traversal
 * @treehgt: total height of the binary tree
 * Return: void
 */
void trav_preorder(heap_t *strnd, heap_t **lstnd, size_t treehgt)
{
	if (!strnd)
		return;
	if (!treehgt)
		*lstnd = strnd;
	treehgt--;
	trav_preorder(strnd->left, lstnd, treehgt);
	trav_preorder(strnd->right, lstnd, treehgt);
}

/**
 * trans_max_heap - change a binary heap into a max heap
 * @root: pointer to the root of the binary heap
 * Return: void
 */
void trans_max_heap(heap_t *root)
{
	int exchval;
	heap_t *currnd, *selnd;

	if (!root)
		return;
	currnd = root;
	while (1)
	{
		if (!currnd->left)
			break;
		if (!currnd->right)
			selnd = currnd->left;
		else
		{
			if (currnd->left->n > currnd->right->n)
				selnd = currnd->left;
			else
				selnd = currnd->right;
		}
		if (currnd->n > selnd->n)
			break;
		exchval = currnd->n;
		currnd->n = selnd->n;
		selnd->n = exchval;
		currnd = selnd;
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of heap
 * Return: the value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int extval;
	heap_t *heaprt, *extnd;

	if (!root || !*root)
		return (0);
	heaprt = *root;
	extval = heaprt->n;
	if (!heaprt->left && !heaprt->right)
	{
		*root = NULL;
		free(heaprt);
		return (extval);
	}
	trav_preorder(heaprt, &extnd, bt_height(heaprt));
	heaprt->n = extnd->n;
	if (extnd->parent->right)
		extnd->parent->right = NULL;
	else
		extnd->parent->left = NULL;
	free(extnd);
	trans_max_heap(heaprt);
	*root = heaprt;
	return (extval);
}
