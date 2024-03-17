#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int kadens(int arr[], int size)
{
    int i = 0;
    int max = arr[0];
    int curr = 0;
    while (i < size)
    {
        curr = (curr < 0) ? 0 : curr;
        curr += arr[i];
        max = (curr > max) ? curr : max;
        i++;
    }
    return (max);
}

int slidingWindow(int arr[], int size)
{
    int l = 0;
    int r = 0;
    int win_start_pos = 0;
    int win_end_pos = 0;
    int curr = 0;
    int max = arr[0];

    while (r < size)
    {
        if (curr < 0)
        {
            curr = 0;
            l = r;
        }
        curr += arr[r];
        if (curr > max)
        {
            max = curr;
            win_start_pos = l;
            win_end_pos = r;
        }
        r++;
    }
    curr = 0;
    while (win_start_pos <= win_end_pos)
        curr += arr[win_start_pos++];
    return (curr);
}

int main( void )
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Kaden's Algorithm : %d\n", kadens(arr, size));
    printf("Sliding Window Technique: %d\n", slidingWindow(arr, size));

}