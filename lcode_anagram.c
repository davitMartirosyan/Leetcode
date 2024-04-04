#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char *toLower(char *s)
{
    char *lowerCaseWord = malloc(sizeof(char) * strlen(s));
    if (!lowerCaseWord)
        exit(EXIT_FAILURE);
    int i = 0;
    while (i < (int)strlen(s))
    {
        lowerCaseWord[i] = tolower(s[i]);
        i++;
    }
    return (lowerCaseWord);
}

bool isAnagram(char *s, char *t)
{
    char *ls = toLower(s);
    char *lt = toLower(t);

    int alpha[26] = {};
    int i = -1;
    while (++i < (int)strlen(ls))
        alpha[ ls[i] - 'a' ]++;
    i = -1;
    while (++i < (int)strlen(lt))
        alpha[ lt[i] - 'a']--;
    i = -1;
    while (++i < 26)
        if (alpha[i] != 0)
            return (false);
    return (true);
}

int main( void )
{
    char *c10 = "anagram";
    char *c11 = "nagaram";

    char *c20 = "rat";
    char *c21 = "car";

    char *c30 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    char *c31 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbba";

    if (isAnagram(c10, c11))
        printf("%s : is anagram\n", c11);
    if (isAnagram(c20, c21))
        printf("%s : is anagram\n", c21);
    if (isAnagram(c30, c31))
        printf("%s : is anagram\n", c31);
}