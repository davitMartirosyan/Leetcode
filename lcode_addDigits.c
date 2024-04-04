#include <stdio.h>
#include <stdlib.h>

int addDigits(int n)
{
    int s = 0;
    while (n)
    {
        s += n %10;
        n /= 10;
    }
    return (s);
}

int main( void )
{
    int num = 2563;
    while (num > 9)
        num = addDigits(num);
    printf("Num: %d\n", num);
}