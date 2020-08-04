#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	new_node = insertion_heap(*root, value, 0, h_size(*root) + 1);
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		new_node->n = new_node->parent->n;
		new_node->parent->n = value;
		new_node = new_node->parent;
	}
	return (new_node);
}

/**
 * h_size - size of a tree
 * @root: root of the tree
 * Return: size
 */
int h_size(binary_tree_t *root)
{
	if (!root)
		return (0);
	return (1 + h_size(root->left) + h_size(root->right));
}

/**
 * insertion_heap - insert into a binary tree
 * @root: root of the tree
 * @value: value new node
 * @i: index of node
 * @size: position to insert
 * Return: new pointer inserted
 */
heap_t *insertion_heap(binary_tree_t *root, int value, int i, int size)
{
	heap_t *new_node;

	if (!root)
		return (0);
	if (i + 1 == size / 2)
	{
		if (size % 2 == 1)
		{
			root->right = binary_tree_node(root, value);
			return (root->right);
		}
		else
		{
			root->left = binary_tree_node(root, value);
			return (root->left);
		}
	}
	new_node = insertion_heap(root->left, value, 2 * i + 1, size);
	if (new_node)
		return (new_node);
	return (insertion_heap(root->right, value, 2 * i + 2, size));
}
