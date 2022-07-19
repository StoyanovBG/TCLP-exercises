#include <stdio.h>
#include <ctype.h>

char getch(void);
char ungetch(int c);
int getint(int *pn);
float getfloat(float *pn);

int main()
{
    int n; float f;
    getint(&n); getfloat(&f);
    printf("%d\n %f", n, f);
    return 0;
}

char getch(void)
{
    char ch;
    ch = getchar();
    if (ch == '\n')
        return '\0';
    else
        return ch;
}

char ungetch(int c)
{
    if (c != EOF){
        ungetc(c, stdin);
        return c;
    }
    else
        return EOF;
}

int getint(int *pn)
{
    int c, sign;
    *pn = 0;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }
    while (isdigit(c)) {
        *pn = 10 * *pn + (c - '0');
        c = getch();
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

float getfloat(float *pn)
{
    int c, sign;
    *pn = 0;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(sign == 1 ? '+' : '-');
            return 0;
        }
    }
    while (isdigit(c)) {
        *pn = 10 * *pn + (c - '0');
        c = getch();
    }
    if (c == '.') {
        c = getch();
        while (isdigit(c)) {
            *pn = 10 * *pn + (c - '0');
            c = getch();
        }
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
