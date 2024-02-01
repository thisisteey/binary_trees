#include "binary_trees.h"

/**
 * mem_realloc - adjusts memory allocation
 * @prevmem: pointer to the existing memory block
 * @oldmemsz: size of the original memory block
 * @newmemsz: size of the desired memory block
 * Return: void
 */
void *mem_realloc(void *prevmem, unsigned int oldmemsz, unsigned int newmemsz)
{
	void *newmem;
	unsigned int idx;
	unsigned int minsz = oldmemsz < newmemsz ? oldmemsz : newmemsz;

	if (newmemsz == oldmemsz)
		return (prevmem);
	if (prevmem)
	{
		if (newmemsz == 0)
		{
			free(prevmem);
			return (NULL);
		}
		newmem = malloc(newmemsz);
		if (newmem)
		{
			for (idx = 0 ; idx < minsz ; idx++)
				*((char *)newmem + idx) = *((char *)prevmem + idx);
			free(prevmem);
			return (newmem);
		}
		free(prevmem);
		return (NULL);
	}
	else
	{
		newmem = malloc(newmemsz);
		return (newmem);
	}
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted array of ints
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 * Return: pointer to sorted array in descending order
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arr = NULL, extval;
	heap_t *currnd;
	size_t arrsz = 0;

	if (heap)
	{
		currnd = heap;
		while (currnd)
		{
			extval = heap_extract(&currnd);
			arr = mem_realloc(arr, sizeof(int) * arrsz, sizeof(int) * (arrsz + 1));
			*(arr + arrsz) = extval;
			arrsz++;
		}
	}
	if (size)
		*size = arrsz;
	return (arr);
}
