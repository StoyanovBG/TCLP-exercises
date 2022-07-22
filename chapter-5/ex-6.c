#include <stdio.h>
#include <ctype.h>
#include <string.h>

void get_line(char *s);
int atoi_n(const char *s);
int getop(char *s);
void reverse(char *s);
void itoa_n(char *s, int n);
int strindex(char *s, char *t);

int main(void)
{
    char string[150] = "";
    get_line(string);
    puts(string);

    char *s = "12s3a";
    printf("%d", atoi_n(s));

    char s1[100] = "";
    int type = getop(s1);
    printf("%d ", type);
    puts(s1);

    int i = 1234;
    char s2[100] = "";
    itoa_n(s2, i);
    printf("itoa: %s\n", s2);

    char s3[] = "first second third";
    char t[] = "second";
    printf("%d", strindex(s3, t));
    
    return 0;
}

void get_line(char *s)
{
    while ((*s = getchar()) != EOF && (*s != '\n')){
        ++s;
    }
    *s = '\0';
}
int atoi_n(const char *s)
{
    int i = 0;
    int sign = 1;
    while (*s == ' ')
        s++;
    if (*s == '-'){
        sign = -1;
        s++;
    }
    else if (*s == '+')
        s++;

    while (*s >= '0' && *s <= '9'){
        i = i * 10 + (*s - '0');
        s++;
    }
    return i * sign;
}
int getop(char *s)
{
    char c;
    while ((*s = c = getchar()) != ' ' || c != '\t')
        ;
    *(s + 1) = '\0';
    if (!isdigit(c))
        return c;
    if (isdigit(c) != 0)
        while (isdigit(*(++s) = c = getchar()))
            ;
    if (c == '.'){
        while (isdigit(*(++s) = c = getchar()))
            ;
    }

    if (c != EOF)
        ungetc(c, stdin);
    *s = '\0';
    return 0;
}
void reverse(char *s)
{
    char *t = s + strlen(s) - 1;
    char tmp = 0;
    if (*s == '\0')
        return;
    while (s < t){
        tmp = *t;
        *t-- = *s;
        *s++ = tmp;
    }
}
void itoa_n(char *s, int n)
{
    char *t = s;
    while (n){
        *(t++) = n % 10 + '0';
        n /= 10;
    }
    *t = '\0';
    reverse(s);
}
int strindex(char *s, char *t)
{
    char *first;
    char *second;
    int pos = 0;
    while (*s != '\0'){
        if (*s == *t){
            first = s;
            second = t;
            while (*first++ == *second++){
                if (*second == '\0')
                    return pos;
            }
        }
        pos++;
        s++;
    }
    return -1;
}
