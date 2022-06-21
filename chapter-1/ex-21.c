#include <stdio.h>

#define TAB_LENGTH 20

int main(void)
{
    int c;
    unsigned int spaces = 0, line = 0;

    while ((c = getchar()) != EOF){
        ++line;

        if (c == ' '){
            ++spaces;
            if (line % TAB_LENGTH == 0 && spaces > 1){
                putchar('\t');
                spaces = 0;
            }
        } else{
            while (spaces){
                putchar(' ');
                --spaces;
            }
            if (c == '\n'){
                line = 0;
            }
            putchar(c);
        }
    }
    return 0;
}