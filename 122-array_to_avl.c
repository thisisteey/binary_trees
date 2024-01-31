#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t idx;

	if (array)
	{
		for (idx = 0 ; idx < size ; idx++)
		{
			avl_insert(&tree, *(array + idx));
		}
	}
	return (tree);
}
