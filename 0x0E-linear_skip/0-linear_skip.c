#include "search.h"

/**
 * linear_skip - Entry point
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *val = NULL, *temp = NULL;

	if (!list)
		return (val);
	val = list->express;
	temp = list;
	while (val)
	{
		printf("Value checked at index [%lu] = [%d]\n", val->index, val->n);
		/*
		* if (val->express)
		*	printf("\n%lu, %lu\n",
				val->express->index, temp->express->index);
		*/
		if (val->n >= value || !val->express)
		{
			if (!val->express && val->n < value)
			{
				temp = val;
				while (val->next)
					val = val->next;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
			       temp->index, val->index);
			while (temp)
			{
				printf("Value checked at index [%lu] = [%d]\n",
				       temp->index, temp->n);
				if (temp->n == value)
					return (temp);
				if (temp->n > value)
					return (NULL);
				temp = temp->next;
			}
			break;
		}
		temp = val;
		val = val->express;
	}
	return (NULL);
}
