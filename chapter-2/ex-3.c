#include <stdio.h>

long tolower(const char i);
long htoi(const char s[]);

int main(){
    char s[100];
    scanf("%s", s);
    int n = htoi(s);
    printf("%d\n", n);
    return 0;
}

long tolower(const char i) {
    if (i >= 'A' && i <= 'Z')
        return i + 32;
    return i;
}

long htoi(const char s[])
{
    unsigned long n = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int c = tolower(s[i]);
        if (c == '0' && tolower(s[i+1]) == 'x')
            i++;
        else if (c >= '0' && c <= '9')
            n = 16 * n + (c - '0');
        else if (c >= 'a' && c <= 'f')
            n = 16 * n + (c - 'a' + 10);
    }
    return n;
}