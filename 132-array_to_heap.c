#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created Binary Heap
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t idx;
	heap_t *heaprt = NULL;

	if (array)
	{
		for (idx = 0 ; idx < size ; idx++)
		{
			heap_insert(&heaprt, *(array + idx));
		}
	}
	return (heaprt);
}
