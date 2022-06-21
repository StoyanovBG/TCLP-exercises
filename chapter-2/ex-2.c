#include <stdio.h>

#define LIM 1000

int main(void)
{
    char s[LIM];
    int i = 0, loop = 1;
    while (loop) {
        char c = getchar();
        if (i >= (LIM - 1)) {
            loop = 0;
        } else if (c == '\n') {
            loop = 0;
        } else if (c == EOF) {
            loop = 0;
        }
        s[i++] = c;
    }
    s[i] = '\0';
    printf("%s", s);

    return 0;
}