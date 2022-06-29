#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itoa_n(int n, char s[], int w);

int main()
{
    char s[100];
    int n, w;
    scanf("%d %d", &n, &w);
    itoa_n(n, s, w);
    printf("%s\n", s);
    return 0;
}

void itoa_n(int n, char s[], int w)
{
    int i = 0, sign = 1;
    if (n < 0) {
        sign = (-1);
    }
    do{
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    if (sign < 0) {
        s[i++] = '-';
    }
    w -= i;
    if (w > 0) {
        do {
            s[i++] = ' ';
        } while (--w > 0);
    }
    s[i] = '\0';

    for(i = 0; i < strlen(s) / 2; i++){
        char temp = s[i];
        s[i] = s[strlen(s) - i - 1];
        s[strlen(s) - i - 1] = temp;
    }
}