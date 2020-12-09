#include "search_algos.h"

/**
 * print_array - function to search in all items
 * @array: array to traverse
 * @init: size of array
 * @size: value to search
 * Return: index of item if exist, otherwise -1
 */
void print_array(int *array, int init, int size)
{
	int i;

	printf("Searching in array: ");
	for (i = init; i < size; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}

/**
 * greater - function to search in all items
 * @array: array to traverse
 * @index: size of array
 * @value: value to search
 * Return: index of item if exist, otherwise -1
 */
int greater(int *array, int index, int value)
{
	if (array[index] >= value)
		return (1);
	return (0);
}

/**
 * recursive_binary - function to search in all items
 * @array: array to traverse
 * @first: size of array
 * @last: value to search
 * @value: val
 * Return: index of item if exist, otherwise -1
 */
int recursive_binary(int *array, int first, int last, int value)
{
	int mid;

	if (first < last)
	{
		mid = first + (last - first) / 2;

		print_array(array, first, last);
		if (greater(array, mid, value))
			return (recursive_binary(array, first, mid, value));
		else
			return (recursive_binary(array, mid + 1, last, value));
	}
	if (array[first] == value)
		return (first);
	print_array(array, first, last);
	return (-1);
}
/**
 * advanced_binary - function to search in all items
 * @array: array to traverse
 * @size: size of array
 * @value: value to search
 * Return: index of item if exist, otherwise -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (recursive_binary(array, 0, (int)size - 1, value));
}
