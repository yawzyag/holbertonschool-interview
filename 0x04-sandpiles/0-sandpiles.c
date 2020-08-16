#include "sandpiles.h"


/**
 * print_grid - print grid
 *
 * @grid: sandpile
 *
 * Return: void
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * matriscopy - copy tow matrices
 *
 * @destmat: first matris
 * @srcmat: second matris
 *
 * Return: void
 */
void matriscopy(void *destmat, void *srcmat)
{
	memcpy(destmat, srcmat, 3 * 3 * sizeof(int));
}

/**
 * processMatris - print and toople
 *
 * @grid1: first sand pile
 * @gridcp: second sandpile
 *
 * Return: void
 */
void processMatris(int grid1[3][3], int gridcp[3][3])
{
	int processAgain = 1, i, j, num;

	while (processAgain == 1)
	{
		processAgain = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				num = grid1[i][j];
				if (num >= 4)
				{
					gridcp[i][j] = (gridcp[i][j] - 4);
					if (i + 1 <= 2)
						gridcp[i + 1][j]++;
					if (i - 1 >= 0)
						gridcp[i - 1][j]++;
					if (j + 1 <= 2)
						gridcp[i][j + 1]++;
					if (j - 1 >= 0)
						gridcp[i][j - 1]++;
				}
			}
		}
		matriscopy(grid1, gridcp);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				num = grid1[i][j];
				if (num >= 4)
					processAgain = 1;
			}
		}
		if (processAgain)
		{
			printf("=\n");
			print_grid(grid1);
		}
	}
}

/**
 * sandpiles_sum - Sum sandpiles
 *
 * @grid1: first sand pile
 * @grid2: second sandpile
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int gridcp[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] +  grid2[i][j];
		}
	}
	printf("=\n");
	print_grid(grid1);
	matriscopy(gridcp, grid1);
	processMatris(grid1, gridcp);
}
