#include <stdio.h>

long tolower(const char i);

int main()
{
    char c;
    while ((c = getchar()) != EOF) {
        putchar(tolower(c));
    }
    return 0;
}

long tolower(const char i) 
{
    if (i >= 'A' && i <= 'Z') {
        return i + 32;
    } else {
        return i;
    }
}