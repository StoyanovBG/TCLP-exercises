#include <stdio.h>
#include <string.h>

void itoa_n(int n, char s[]);
void reverse(char s[]);

int main()
{
    char s[100];
    int n = -12345;
    itoa_n(n, s);
    printf("%s\n", s);
    return 0;
}

void itoa_n(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i, j;
    char c;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
