#include <stdio.h>

int miss(int arr[], int n)
{
    int exp = n * (n + 1) / 2;
    int sum = 0;
    while (n--)
        sum += arr[n];
    return (exp - sum);
}

int main( void )
{
    int arr[] = {9,6,4,2,3,5,7,0,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Missing Number: %d\n", miss(arr, size));
}