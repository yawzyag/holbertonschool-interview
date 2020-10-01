#include "slide_line.h"

/**
 * moveToEnd - move to init
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
void moveToEnd(int *line, size_t size)
{
	size_t count1 = 0;
	size_t i = 0;
	int j;
	int lastNonOne = 0;

	for (i = 0; i < size; i++)
		if (line[i] != 1)
			line[count1++] = line[i];

	while (count1 < size)
		line[count1++] = 1;

	for (j = size - 1; j >= 0; j--)
	{
		if (line[j] == 1)
			continue;
		if (!lastNonOne)
		{
			lastNonOne = j;
		}
		if (line[j] != 0)
			line[lastNonOne--] = line[j];
	}

	while (lastNonOne >= 0)
		line[lastNonOne--] = 0;
}

/**
 * moveToInit - move to init
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
void moveToInit(int *line, size_t size)
{
	size_t count = 0, i = 0;

	for (i = 0; i < size; i++)
		if (line[i] != 0)
			line[count++] = line[i];
	while (count < size)
		line[count++] = 0;
}

/**
 * slide_line - move line
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 * @direction: left o right
 *
 * Return: 1 success or 0 failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0;
	int j = 0;

	if (!line || !size)
		return (0);

	if (!direction)
	{
		moveToEnd(line, size);
		j = (int)size;
		while (j > 0)
		{
			/* code */
			if (line[j - 1])
				if (line[j] == line[j - 1])
				{
					line[j--] *= 2;
					line[j] = 0; }
			j--; }
	}
	else
	{
		moveToInit(line, size);
		while (i < size)
		{
			/* code */
			if (line[i + 1])
				if (line[i] == line[i + 1])
				{
					line[i++] *= 2;
					line[i] = 0; }
			i++; }
	}

	if (!direction)
		moveToEnd(line, size);
	else
		moveToInit(line, size);
	return (1);
}
