#include <stdio.h>

void itoa(int n, char s[]);

int main()
{
    char s[100];
    int n = -12345;
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[])
{
    static int i = 0;
    if (n){
        if(n < 0){
            i = 0;
            s[i++] = '-';
            n *= -1;
        }
        int d = n % 10;
        n /= 10;
        itoa(n, s);
        s[i++] = d + '0';
        s[i] = '\0';
    }
}

