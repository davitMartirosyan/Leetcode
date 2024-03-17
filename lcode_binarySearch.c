#include <stdio.h>

int binarySearch(int arr[], int start, int end, int target)
{
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (target > arr[mid])
            return (binarySearch(arr, mid+1, end, target));
        else if (target < arr[mid])
            return (binarySearch(arr, start, mid-1, target));
        return (mid);
    }
    return (-1);
}

int main( void )
{
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", binarySearch(nums, 0, size-1, 9)); // 4
}