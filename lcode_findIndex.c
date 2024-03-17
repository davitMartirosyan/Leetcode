#include <stdio.h>
#include <stdlib.h>
typedef int (*testFunc)(int);

int findIndex(int *arr, int size, int (*testFunc)(int))
{
    int i = -1;
    while (++i < size)
        if (testFunc(arr[i]))
            return (i);
    return (-1);
}

int isPrime(int num)
{
    if (num <= 1)
        return (0);
    if (num <= 3)
        return (1);
    if (num % 2 == 0 || num % 3 == 0)
        return (0);
    for(int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return (0);
    return (1);
}

int main( void )
{
    int arr[] = {10, 2, 3, 44, 1, 22};
    int size = sizeof(arr) / sizeof(arr[0]);
    int idx = findIndex(arr, size, isPrime);
    if (idx < 0)
        printf("Prime Numbers Not Found\n");
    else
        printf("First Prime Number is: %d\n", arr[idx]);
}