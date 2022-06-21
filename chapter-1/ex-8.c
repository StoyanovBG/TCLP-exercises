#include <stdio.h>

int main(void)
{
    int nb = 0; //new blanks
    int nt = 0; //new tabs
    int nl = 0; //new lines

    char c;
    while ((c = getchar()) != EOF) {
        if (c == ' '){
            ++nb;
        }
        else if (c == '\t'){
            ++nt;
        }
        else if (c == '\n'){
            ++nl;
        }
    }

    printf("blanks = \t%d\n", nb);
    printf("tabs = \t%d\n", nt);
    printf("lines = \t%d\n", nl);

    return 0;
}