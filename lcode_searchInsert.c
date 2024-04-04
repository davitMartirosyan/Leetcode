#include <stdio.h>
#include <stdlib.h>

int searchInsert(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = 0;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (target > arr[mid])
            start = mid + 1;
        else if (target < arr[mid])
            end = mid - 1;
        else
            return (mid);
    }
    return (start);
}

int main( void )
{
    int arr[] = {1, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Idx: %d\n", searchInsert(arr, size, 2));
}