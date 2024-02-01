#include "binary_trees.h"

/**
 * bt_size - calculates the size of a binary tree
 * @tree: pointer to the tree to be calculated
 * Return: size of the calculated tree or 0 if tree is empty
 */
size_t bt_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bt_size(tree->left) + bt_size(tree->right) + 1);
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *currtree, *nnode, *trav;
	int totnd, remlf, subsz, bitmsk, treelvl, tmpval;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	currtree = *root;
	totnd = bt_size(currtree);
	remlf = totnd;
	for (treelvl = 0, subsz = 1 ; remlf >= subsz ; subsz *= 2, treelvl++)
		remlf -= subsz;
	for (bitmsk = 1 << (treelvl - 1) ; bitmsk != 1 ; bitmsk >>= 1)
		currtree = remlf & bitmsk ? currtree->right : currtree->left;
	nnode = binary_tree_node(currtree, value);
	remlf & 1 ? (currtree->right = nnode) : (currtree->left = nnode);
	trav = nnode;
	for (; trav->parent && (trav->n > trav->parent->n) ; trav = trav->parent)
	{
		tmpval = trav->n;
		trav->n = trav->parent->n;
		trav->parent->n = tmpval;
		nnode = nnode->parent;
	}
	return (nnode);
}
