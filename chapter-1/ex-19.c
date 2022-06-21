#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char line[], int maxline);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0){
        reverse(line, len);
        printf("%s", line);
        }
    }

int get_line(char line[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        line[i] = c;
    }
    if (c == '\n'){
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    while(c != EOF && c != '\n'){
        ++i;
        c = getchar();
    }
    return i;
}

void reverse(char line[], int maxline)
{
    int i, j;
    char temp;

    for (i = 0, j = maxline - 2; i < j; ++i, --j){
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
    }
}