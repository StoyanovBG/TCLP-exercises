#include <stdio.h>

#define MAXLEN 1000

int main() {
    int c, len = 0, i;
    char line[MAXLEN];

    while (len < MAXLEN - 1 && (c = getchar()) != EOF) {
        if (c != '\n') {
            line[len++] = c;
        }else {
            for (i = len - 1; i >= 0 && (line[i] == ' ' || line[i] == '\t'); --i);
            if (i >= 0) {
                line[i + 1] = '\0';
                printf("%s\n", line);
            }
            len = 0;
        }
    }
    return 0;
}