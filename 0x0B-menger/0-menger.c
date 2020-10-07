#include "menger.h"

/**
 * _pow - print return x raised to y
 * @x: number raised to
 * @y: number to raise
 *
 * Return: num
 */
int _pow(int x, int y)
{
	int sum;

	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);

	sum = _pow(x, y / 2);

	if (y % 2 == 0)
		return (sum * sum);
	else
		return (x * sum * sum);
}

/**
 * printBox - Function to print box
 *
 * @level: Arguments counter
 *
 * Return: void
 */
void printBox(int level)
{
	int i, j, status = -1, y, z;

	for (i = 0; i < (_pow(3, level)); i++)
	{
		/* code */
		for (j = 0; j < (_pow(3, level)); j++)
		{
			/* code */
			status = -1;
			for (y = i, z = j; y && z; y /= 3, z /= 3)
				if (y % 3 == 1 && z % 3 == 1)
					status = 0;
			if (status == 0)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}

/**
 * menger - Function to create face of sponge
 *
 * @level: Arguments counter
 *
 * Return: void
 */
void menger(int level)
{

	if (level)
		printBox(level);
}
