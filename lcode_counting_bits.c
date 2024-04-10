#include <stdio.h>
#include <stdlib.h>

int bitCount(int n)
{
    int bits = 0;
    while (n)
    {
        bits += ((n & 1) == 1) ? 1 : 0;
        n >>= 1;
    }
    return (bits);
}

int main(int ac, char **av)
{
    int *bitset;
    int n_opp;
    int n;
    if (ac != 2)
        exit(EXIT_FAILURE);
    n = atoi(av[1]);
    if (!n || n < 0)
        exit(EXIT_FAILURE);
    n_opp = 0;
    bitset = malloc(sizeof(int) * (n + 1));
    if (!bitset)
        exit(EXIT_FAILURE);
    int i = 0;
    while (n_opp <= n)
    {
        bitset[i] = bitCount(n_opp);
        i++;
        n_opp++;
    }
    free(bitset);
}
