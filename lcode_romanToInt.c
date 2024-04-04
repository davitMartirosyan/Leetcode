#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void match(char c, int *n, char roman[], int numerals[])
{
    int i = 0;

    while (i < 7)
    {
        if (c == roman[i])
            break;
        i++;
    }
    *n += numerals[i];
}

int romanToInt(char *r)
{
    if (!r)
        return (0);
    int i = 0;
    int n = 0;
    char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int numerals[7] = {1, 5, 10, 50, 100, 500, 1000};
    while (i < (int)strlen(r))
    {
        if (r[i] == 'I' && (r[i+1] == 'V' || r[i+1] == 'X'))
            n -= 2;
        else if (r[i] == 'X' && (r[i+1] == 'L' || r[i+1] == 'C'))
            n -= 20;
        else if (r[i] == 'C' && (r[i+1] == 'D' || r[i+1] == 'M'))
            n -= 200;
        match(r[i], &n, roman, numerals);
        i++;
    }
    return (n);
}

int main( void )
{
    char* r = "XXI";
    printf("%d\n", romanToInt(r));
}