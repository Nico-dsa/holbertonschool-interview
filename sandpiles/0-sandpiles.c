#include "sandpiles.h"

/**
 * is_stable - checks if sandpile is stable.
 * @grid: grid to check
 * Return: 1 if stable else 0
 */

int is_stable(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return (0);
        }
    }
    return (1);
}

/**
 * topple - topples the sandpile to distribute sand
 * @grid: grid to topple
 */

void topple(int grid[3][3])
{
    int tempGrid[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tempGrid[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                tempGrid[i][j] -= 4;

                if (i - 1 >= 0)
                    tempGrid[i - 1][j]++;
                if (i + 1 < 3)
                    tempGrid[i + 1][j]++;
                if (j - 1 >= 0)
                    tempGrid[i][j - 1]++;
                if (j + 1 < 3)
                    tempGrid[i][j + 1]++;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] += tempGrid[i][j];
        }
    }
}

/**
 * sandpiles_sum - compute the sum of two sandpiles.
 * @grid1: first sandpile
 * @grid2: second sandpile
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
    while (!is_stable(grid1))
    {
        printf("=\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j)
                    printf(" ");
                printf("%d", grid1[i][j]);
            }
            printf("\n");
        }
        topple(grid1);
    }
}
