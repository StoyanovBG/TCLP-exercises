#include <stdio.h>

static int buf[2] = {0, 0};
static int ptr = 0;

int getch(void);
void ungetch(int);

int main(void)
{
    int c;
    while ((c = getch()) != EOF)
        printf("%c", c);
    return 0;
}

int getch(void)
{
    if (ptr > 0)
        ptr--;
    else
        scanf("%d", &buf[ptr]);
    return buf[ptr];
}

void ungetch(int c)
{
    if (ptr < 2)
        buf[ptr++] = c;
}
