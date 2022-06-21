#include <stdio.h>

int main(void)
{
    char c; //character variable
    char last; //previous / last character variable
    while ((c = getchar()) != EOF){
        if (c != ' ' || last != ' '){
            putchar(c);
        }
        last = c;
    }
    return 0;
}