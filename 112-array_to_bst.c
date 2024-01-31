#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created BST, or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t idx;
	bst_t *tree_root = NULL;

	for (idx = 0 ; idx < size ; idx++)
	{
		bst_insert(&tree_root, array[idx]);
	}
	return (tree_root);
}
