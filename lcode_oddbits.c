#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac != 2)
        exit(EXIT_FAILURE);
    int n = atoi(av[1]); // 01101011
    int eo = 0;
    int i = n;
    if (n < 0)
    {
        int e = 0;
        while (e < 31)
        {
            eo += i & 1;
            i >>= 1;
            e++;
        }
    }
    else
    {
        while (i)
        {
            eo += i & 1;
            i >>= 1;
        }
    }
    
    if ((eo & 1) == 1)
        printf("Bits are odd\n");
    else
        printf("Bits are even\n");
    return (0);
}