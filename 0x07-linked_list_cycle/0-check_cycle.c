#include "lists.h"

/**
 * check_cycle - chech for cycle in loinked list
 * @list: pointer to head of list
 * Return: 1 if coincidence 0 else
 */
int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	if (!list)
		return (0);
	else
	{
		slow = list;
		fast = list->next;
		while (slow != fast)
		{
			slow = slow->next;
			if (!slow)
				return (0);
			fast = fast->next;
			if (!fast)
				return (0);
			fast = fast->next;
			if (!fast)
				return (0);
		}
	}
	return (1);
}
