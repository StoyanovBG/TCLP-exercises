#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void delete_comments(char line[]);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0){
        delete_comments(line);
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

void delete_comments(char line[]) {
    int i, j;
    char c;
    for (i = 0, j = 0; line[i] != '\0'; ++i) {
        c = line[i];
        if (c == '/') {
            if (line[i + 1] == '/') {
                line[i] = '\0';
                break;
            } else if (line[i + 1] == '*') {
                line[i] = '\0';
                while (line[i] != '*' || line[i + 1] != '/') {
                    ++i;
                }
            }
        }
    }
}