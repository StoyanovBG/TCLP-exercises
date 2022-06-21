#include <stdio.h>

#define IN	1
#define OUT	0

int main()
{
    char c;
    int state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            if (state == OUT)
                state = IN ;
            putchar(c) ;
        }
        else if (state == IN) {
            state = OUT ;
            putchar('\n') ;
        }
    }
    return 0;
}