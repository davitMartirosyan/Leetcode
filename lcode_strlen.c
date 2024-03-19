#include <stdio.h>

int strlenr(char *s)
{
    if (*s == '\0')
        return (0);
    return (strlenr(++s) + 1);
}

int main( void )
{
    char str[] = "Hello";
    printf("%d\n", strlenr(str));
}