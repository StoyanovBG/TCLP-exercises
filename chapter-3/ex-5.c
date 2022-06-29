#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);

int main()
{
    char s[100];
    int n;
    scanf("%d", &n);
    itob(n, s, 16);
    printf("%s\n", s);
    return 0;
}

void itob(int n, char s[], int b)
{
    int i, j = 0, c;
    if (n == 0) {
        s[j++] = '0';
    }

    for (i = n; i > 0; i /= b){
        if ((c = i % b) <= 9) {
            s[j++] = c + '0';
        }else {
            s[j++] = c - 10 + 'A';
        }
    }
    s[j++] = '\0';

    for (i = 0; i < strlen(s) / 2; i++){
        char temp = s[i];
        s[i] = s[strlen(s) - i - 1];
        s[strlen(s) - i - 1] = temp;
    }
}
