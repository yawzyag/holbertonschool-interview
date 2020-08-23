#include "lists.h"

/**
 * listint_len - number of nodes
 * @h: node
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	int counter = 0;

	if (!h)
		return (0);
	while (h)
	{
		h = h->next;
		counter++;
	}
	return (counter);
}

/**
 * is_palindrome - chek if is palindrome
 * @head: pointer to head of list
 * Return: 1 if palindrome 0 else
 */
int is_palindrome(listint_t **head)
{
	int len, i, j;
	int arr[1000000];

	len = listint_len(*head);
	for (i = 0; i <= len - 1; i++)
	{
		arr[i] = (*head)->n;
		(*head) = (*head)->next;
	}
	i--;
	for (j = 0, i; j < len; j++, i--)
	{
		if (arr[j] != arr[i])
			return (0);
	}
	return (1);
}
