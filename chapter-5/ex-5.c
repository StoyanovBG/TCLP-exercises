#include <stdio.h>

void strncpy_n(char *s, char *t, int n);
void strncat_n(char *s, char *t, int n);
int strncmp_n(char *s, char *t, int n);

int main()
{
    char s[100] = "123456";
    char t[100] = "7890";
    int n = 3;
    strncpy_n(s, t, n);
    printf("%s\n", s);
    char s2[100] = "123456";
    char t2[100] = "7890";
    strncat_n(s2, t2, n);
    printf("%s\n", s);
    char s3[100] = "123456";
    char t3[100] = "7890";
    printf("%d\n", strncmp_n(s3, t3, n));
    return 0;
}

void strncpy_n(char *s, char *t, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        s[i] = t[i];
    }
    s[i] = '\0';
}
void strncat_n(char *s, char *t, int n)
{
    int i, j;
    for (i = 0; s[i] != '\0'; i++)
    {
    }
    for (j = 0; j < n; j++)
    {
        s[i + j] = t[j];
    }
    s[i + j] = '\0';
}
int strncmp_n(char *s, char *t, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            return 1;
        }
    }
    return 0;
}
