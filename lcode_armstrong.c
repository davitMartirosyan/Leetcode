#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_armstrong(int n)
{
    int zangvac[7] = {};
    int armstrong = 0;
    int i = n;
    int idx = 0;

    while (i != 0)
    {
        zangvac[idx++] = (i % 10);
        i /= 10;
    }
    i = 0;
    while (i < idx)
    {
        armstrong += pow(zangvac[i], idx);
        i++;
    }
    return (armstrong == n ? true : false);
}

int main(int ac, char **av)
{
    int n;
    if (ac != 2)
        exit(EXIT_FAILURE);
    n = atoi(av[1]);
    if (n < 0)
        n *= -1;
    if (is_armstrong(n))
        printf("YES\n");
    else
        printf("NO\n");
    return (0);
}