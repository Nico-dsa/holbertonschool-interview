#include <stdio.h>
#include <stdbool.h>

#include "sandpiles.h"

void print_sandpiles(int grid1[3][3], int grid2[3][3]);
void print_grid(int grid[3][3]);
bool is_stable(int grid[3][3]);
void topple(int grid[3][3]);

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    // Afficher les sabliers avant la somme
    print_sandpiles(grid1, grid2);

    // Somme des sabliers
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Afficher la grille après la somme
    printf("=\n");
    print_grid(grid1);

    // Écrouler jusqu'à stabilisation
    while (!is_stable(grid1)) {
        topple(grid1);
        print_grid(grid1);
    }
}

void print_sandpiles(int grid1[3][3], int grid2[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", grid1[i][j]);
        }
        if (i == 1) {
            printf("+ ");
        } else {
            printf("  ");
        }
        for (int j = 0; j < 3; ++j) {
            printf("%d ", grid2[i][j]);
        }
        printf("\n");
    }
}

void print_grid(int grid[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_stable(int grid[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] > 3) {
                return false;
            }
        }
    }
    return true;
}

void topple(int grid[3][3]) {
    int temp[3][3] = {0};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] > 3) {
                temp[i][j] -= 4;
                if (i > 0) temp[i - 1][j]++; // Up
                if (i < 2) temp[i + 1][j]++; // Down
                if (j > 0) temp[i][j - 1]++; // Left
                if (j < 2) temp[i][j + 1]++; // Right
            }
        }
    }

    // Apply the toppling
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] += temp[i][j];
        }
    }
}
