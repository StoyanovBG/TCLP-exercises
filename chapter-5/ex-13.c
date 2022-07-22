#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tail(int n, char *str);

// $ tail -n 10 < file.txt

int main(int argc, char *argv[]) {
    int n = 10;
    char *str;
    str = (char *)malloc(sizeof(char) * (n + 1));
    fgets(str, n + 1, stdin);
    if (argc == 2) {
        n = atoi(argv[1]);
    }
    tail(n, str);
    free(str);
    return 0;
}

void tail(int n, char *str)
{
    int i;
    for (i = strlen(str) - 1; i >= 0; i--){
        if (n == 0)
            break;
        printf("%c", str[i]);
        n--;
    }
}
