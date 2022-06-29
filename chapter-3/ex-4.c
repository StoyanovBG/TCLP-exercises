#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itoa_n(long int n, char *s);

int main() 
{
    char s[100];
    itoa_n(-2147483648, s);
    printf("%s\n", s);
    return 0;
}

void itoa_n(long int n, char *s)
{
    int i = 0, sign = n;
    do{
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    if (sign < 0){
        s[i++] = '-';
    }
    s[i] = '\0';
    int s_len = strlen(s);
    for (int j = 0; j < s_len / 2; j++){
        char temp = s[j];
        s[j] = s[s_len - j - 1];
        s[s_len - j - 1] = temp;
    }
}
