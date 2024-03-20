#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int ac, char **av)
{
    if (ac < 3)
        exit(1);
    int x = atoi(av[1]);
    int y = atoi(av[2]);
    int i = 0;
    int k = 3;
    if ((x * y) != (ac - 3))
        exit(1);
    int **matrix = malloc(sizeof(int*) * (x));
    int **matrix_traverse = malloc(sizeof(int) * (y));
    if (!matrix)
        exit(1);
    insert(matrix, av, x, y, k);
    insert(matrix_traverse, av, y, x, k);

    i = 0;
    while (i < x)
    {
        int j = 0;
        while (j < y)
        {
            swap(&matrix[i][j], &matrix_traverse[j][i]);
            j++;
        }
        i++;
    }

    printMatrix(matrix, x, y);
    printf("\n");
    printMatrix(matrix_traverse, y, x);



    i = -1;
    while (++i < x)
    {
        free(matrix[i]);
        free(matrix_traverse[i]);
    }

}