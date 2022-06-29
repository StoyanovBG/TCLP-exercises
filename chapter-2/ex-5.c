#include <stdio.h>

#define MAX 1000

int any(char *s1, char *s2);

int main(void)
{
    char s1[MAX], s2[MAX];
    scanf("%s %s", s1, s2);
    printf("%d", any(s1, s2));
    return 0;
}

int any(char *s1, char *s2)
{
    int i, j;
    for (i = 0; s1[i] != '\0'; i++){
        for (j = 0; s2[j] != '\0'; j++){
            if (s1[i] == s2[j]){
                return i;
            }
        }
    }
    return -1;
}