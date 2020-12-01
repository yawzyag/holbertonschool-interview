#include "sort.h"

/**
 * heap_sort - sort an array sift-down
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	unsigned int n = size, i = n / 2, parent, child;
	int t;

	for (;;)
	{
		if (i > 0)
		{
			i--;
			t = array[i];
		}
		else
		{
			n--;
			if (n == 0)
				return;
			t = array[n];
			array[n] = array[0];
		}
		parent = i;
		child = i * 2 + 1;
		while (child < n)
		{
			if (child + 1 < n && array[child + 1] > array[child])
				child++;

			if (array[child] > t)
			{
				array[parent] = array[child];
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
		array[parent] = t;
		print_array(array, size);
	}
}
