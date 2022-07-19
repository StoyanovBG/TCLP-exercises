#include <stdio.h>
#include <string.h>

int strend(char*, char*);

int main()
{
    char s[100];
    char t[100];
    scanf("%s %s", s, t);
    printf("%d\n", strend(s, t));
    return 0;
}

int strend(char* s, char* t)
{
    s += strlen(s) - strlen(t);
    while(*s && *s++ == *t++);
    return !*s;
}
