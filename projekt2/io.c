#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int read_word(char *s, int max, FILE *f)
{
    int c;
    int index = 0;

    while (isspace(c = getc(f)) && c != EOF);
    s[index++] = c;

    while (!(isspace(c = getc(f))))
    {
        if (c == EOF)
            return EOF;
        s[index++] = c;
        if (index == max - 1)
        {
            while (isspace(c = getc(f)) && c != EOF);
            s[index] = '\0';
            return index + 1;
        }
    }
    s[index] = '\0';
    return index + 1; 
}

/*int main(void)
{
    FILE *f = fopen("data.txt", "r");
    char s[1000];
    int max;

    while (read_word(s, max, f) != EOF)
    {
        printf("%s\n", s);
        printf("%d\n", max);
    }
    return 0;
}*/
