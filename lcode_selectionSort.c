#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int arr[], int size)
{
    int i = 0;
    int minIdx = 0;
    while (i < size)
    {
        minIdx = i;
        int j = i + 1;
        while (j < size)
        {
            if (arr[j] < arr[i])
                minIdx = j;
            j++;
        }
        swap(&arr[i], &arr[minIdx]);
        i++;
    }
}

int main( void )
{
    int arr[] = {2,1,5,3,10,8,9,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    int i = -1;
    while (++i < size)
        printf("%d ", arr[i]);
    printf("\n");
}