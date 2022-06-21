#include <stdio.h>

#define TAB_LENGTH 20

int main(void)
{
    int c;
    unsigned int spaces;

    while ((c = getchar()) != EOF){
        if (c == '\t'){
            spaces = TAB_LENGTH;

            while (spaces){
                putchar(' ');
                --spaces;
            }
        }
        else{
            putchar(c);
        }
    }
    return 0;
}