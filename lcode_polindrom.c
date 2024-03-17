#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int reverse(int n)
{
    int n_reverse = 0;
    while (n)
    {
        n_reverse = n_reverse * 10 + (n%10);
        n /= 10;
    }
    return (n_reverse);
}

bool is_palindrom(int n)
{
    char digits[8];
    int idx = 0;
    int i = n;
    int j = 0;
    while (i)
    {
        digits[idx++] = (char)(i % 10) + '0';
        i /= 10;
    }
    digits[idx] = '\0';
    i = 0;
    j = idx-1;
    while (i <= j)
    {
        if (digits[i] != digits[j])
            return (false);
        i++;
        j--;
    }
    return (true);
}

void print(int palindromNumber, int totalSteps)
{
    printf("Palindrom Number: %d\n", palindromNumber);
    printf("Total Steps: %d\n", totalSteps);
    exit(0);
}

int main(int ac, char **av)
{
    if (ac != 2)
        exit(EXIT_FAILURE);

    int n;
    int n_reverse;
    int palindromNumber;
    int totalSteps;

    n = atoi(av[1]);
    totalSteps = 0;
    if (n < 0)
        n *= -1;
    if (is_palindrom(n))
        print(n, totalSteps);
    n_reverse = reverse(n);

    while (true)
    {
        palindromNumber = n + n_reverse;
        totalSteps++;
        if (is_palindrom(palindromNumber))
            break;
        n = palindromNumber;
        n_reverse = reverse(n);
    }
    print(palindromNumber, totalSteps);
    return (0);

}