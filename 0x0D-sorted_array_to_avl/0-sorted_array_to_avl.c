#include "binary_trees.h"
#include "extra.c"

/**
* sortedArrayToBST - insert node bst
* @tree: tree of the root
* @array: tree of the root
* @start: value to insert
* @end: end
* Return: return node
*/
avl_t *sortedArrayToBST(avl_t **tree, int *array, int start, int end)
{
	int mid;
	avl_t *root = NULL;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	root = bst_insert(tree, array[mid]);

	root->left = sortedArrayToBST(tree, array, start, mid - 1);

	root->right = sortedArrayToBST(tree, array, mid + 1, end);

	return (root);
}

/**
* sorted_array_to_avl - sorted array to binary tree
*
* @array: The array to be printed
* @size: Size of the array
* Return: avl_t head
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	sortedArrayToBST(&root, array, 0, size - 1);

	return (root);
}
