#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - adds a new sorted node
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to insert
 * Return: address of the head
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current_node;
	listint_t *aux;

	if (!head)
		return (0);
	new_node = (listint_t *)malloc(sizeof(listint_t));
	if (!new_node)
		return (0);
	new_node->n = number;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}
	if (number <= (*head)->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	current_node = *head;
	while (current_node)
	{
		if (current_node->n < number)
		{
			aux = current_node;
			current_node = current_node->next;
		}
		else
			current_node = NULL;
	}
	new_node->next = aux->next;
	aux->next = new_node;
	aux = NULL;
	return (new_node);
}