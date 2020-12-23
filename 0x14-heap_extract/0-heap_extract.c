#include "binary_trees.h"

/**
 * heap_extract - Stores recursively each level in an array of strings
 *
 * @root: Pointer to the node to print
 *
 * Return: 0 on success, error code on failure
 */

int heap_extract(heap_t **root)
{
	int val;
	heap_t *temp;

	if (!root || !*root)
		return (0);
	temp = *root;
	val = temp->n;
	if (!temp->left && !temp->right)
	{
		*root = NULL;
		free(temp);
		return (val);
	}
	return (0);
}
