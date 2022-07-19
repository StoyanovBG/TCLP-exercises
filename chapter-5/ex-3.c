#include <stdio.h>

void strcat(char *s, char *t);

int main(void)
{
    char s[100] = "first";
    char s2[] = " second";
    strcat(s, s2);
    puts(s);

    return 0;
}

void strcat(char *s, char *t)
{
    while ((*++s) != '\0')
        ;
    while ((*s++ = *t++) != '\0')
        ;
}
