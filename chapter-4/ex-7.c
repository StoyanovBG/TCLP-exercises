#include <stdio.h>

void gets(char s[]);
void ungets(char s[]);
void getch(char *ch);
void ungetch(char ch);

int main()
{
    char s[100];
    gets(s);
    ungets(s);
    return 0;
}

void gets(char s[])
{
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n'){
        s[i] = ch;
        i++;
    }
    s[i] = '\0';
}

void ungets(char s[])
{
    int i;
    for (i = 0; s[i] != '\0'; i++){
        ungetc(s[i], stdin);
    }
}

void getch(char *ch)
{
    *ch = getchar();
}

void ungetch(char ch)
{