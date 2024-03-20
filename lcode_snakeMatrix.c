#include <stdio.h>
#include <stdlib.h>

void insert(int **matrix, char **av, int x, int y, int k)
{
    int i = 0;
    while (i < x)
    {
        matrix[i] = malloc(sizeof(int) * (y));
        int j = 0;
        while (j < y)
        {
            matrix[i][j] = atoi(av[k]);
            k++;
            j++;
        }
        i++;
    }
}

void printMatrix(int *matrix[], int x, int y)
{
    int i = 0;
    while (i < x)
    {
        int j = 0;
        while (j < y)
            printf("%d ", matrix[i][j++]);
        printf("\n");
        i++;
    }
}

void printMatrix_snake(int *matrix[], int x, int y)
{
    int i = 0;
    while (i < x)
    {
        if ((i & 1) == 1)
        {
            int j = y - 1;
            while (j >= 0)
                printf("%d ", matrix[i][j--]);
            printf("\n");
        }
        else
        {
            int j = -1;
            while (++j < y)
                printf("%d ", matrix[i][j]);
            printf("\n");
        }
        i++;
    }
}

int main(int ac, char **av)
{
    int x = 3;
    int y = 3;
    int **matrix = malloc(sizeof(int*) * (x));
    if (!matrix)
        exit(1);
    if (ac - 1 < (x * y))
        exit(1);
    insert(matrix, av, x, y, 1);
    printMatrix_snake(matrix, x, y);

    int i = -1;
    while (++i < x)
        free(matrix[i]);
    free(matrix);
}