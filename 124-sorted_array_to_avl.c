#include "binary_trees.h"

/**
 * avl_sorted_build - constructs an AVL tree from an array
 * @root: double pointer to the root node of the subtree
 * @array: pointer to the array element to be changed
 * @minidx: minimum index
 * @maxidx: maximum index
 * Return: void
 */
void avl_sorted_build(avl_t **root, int *array, size_t minidx, size_t maxidx)
{
	avl_t *nnode = NULL;
	size_t mididx;

	if (maxidx - minidx > 1)
	{
		mididx = (maxidx - minidx) / 2 + minidx;
		nnode = binary_tree_node(*root, array[mididx]);
		if (array[mididx] > (*root)->n)
		{
			(*root)->right = nnode;
		}
		else if (array[mididx] < (*root)->n)
		{
			(*root)->left = nnode;
		}
		avl_sorted_build(&nnode, array, minidx, mididx);
		avl_sorted_build(&nnode, array, mididx, maxidx);
	}
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avltree = NULL;
	size_t mididx;

	if (!array)
		return (NULL);
	mididx = (size - 1) / 2;
	avltree = binary_tree_node(NULL, array[mididx]);
	avl_sorted_build(&avltree, array, -1, mididx);
	avl_sorted_build(&avltree, array, mididx, size);
	return (avltree);
}
