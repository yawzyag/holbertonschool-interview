#include "binary_trees.h"

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * preorder - Preorder traverse
 *
 * @tree: Pointer to the root
 * @node: Pointer to the root
 * @h: height of heap
 * @lvl: level of heap
 *
 * Return: 0 on success, error code on failure
 */

void preorder(heap_t *tree, heap_t **node, size_t h, size_t lvl)
{
	if (!tree)
		return;
	if (h == lvl)
		*node = tree;
	lvl++;
	if (tree->left)
		preorder(tree->left, node, h, lvl);
	if (tree->right)
		preorder(tree->right, node, h, lvl);
}

/**
 * heapify - check and fix the heap
 *
 * @temp: Pointer to the temporal node
 */
void heapify(heap_t *temp)
{
	heap_t *orgin;
	int temVal;

	preorder(temp, &orgin, _height(temp), 0);
	while (temp->left || temp->right)
	{
		if (!temp->right || temp->left->n > temp->right->n)
		{
			temVal = temp->n;
			temp->n = temp->left->n;
			temp->left->n = temVal;
			temp = temp->left;
		}
		else if (!temp->left || temp->left->n < temp->right->n)
		{
			temVal = temp->n;
			temp->n = temp->right->n;
			temp->right->n = temVal;
			temp = temp->right;
		}
	}

	if (orgin->parent->right)
		orgin->parent->right = NULL;
	else
		orgin->parent->left = NULL;
	temp->n = orgin->n;
	free(orgin);
}

/**
 * heap_extract - Delete the root node
 *
 * @root: Pointer to the root
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

	heapify(temp);
	return (val);
}
