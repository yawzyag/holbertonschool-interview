#include "binary_trees.h"
/**
* binary_tree_node - function to create a binary tree
* @parent: node parent
* @value:  the value of the new node
* Return: New node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *temp = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (!temp)
		return (NULL);

	temp->n = value;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = parent;
	return (temp);
}

/**
* insert - function to insert
* @tree: root of check
* @padre: parent
* @value: valor to insert
* Return: the node
*/
avl_t *insert(avl_t **tree, avl_t *padre, int value)
{
	if (!*tree)
		*tree = binary_tree_node(padre, value);
	else if (value < (*tree)->n)
		return (insert(&(*tree)->left, *tree, value));
	else if (value > (*tree)->n)
		return (insert(&(*tree)->right, *tree, value));
	else
		return (NULL);

	return (*tree);
}

/**
* bst_insert - insert node bst
* @tree: tree of the root
* @value: value to insert
* Return: return node
*/
avl_t *bst_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);

	return (insert(tree, NULL, value));
}
