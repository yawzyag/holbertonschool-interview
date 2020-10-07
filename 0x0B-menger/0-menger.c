#include "menger.h"

/**
 * menger - Function to create face of sponge
 *
 * @level: Arguments counter
 *
 * Return: void
 */
void menger(int level)
{
	int n = 1 << 2 * level, x;

	for (x = n * n; x--;)
		if (!(x & x / 2 & n * n / 3))
			printf(x & x / n & n / 3 ? " " : x & (n - 1) ? "#" : "#\n");
}
