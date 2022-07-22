#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void entab(char *s, int tabstop);
void detab(char *s);

int main()
{
    char s[100];
    int tabstop = 7;
    printf("Enter a string: ");
    scanf_s("%s", s, 100);
    entab(s, tabstop);
    printf("%s\n", s);
    detab(s);
    printf("%s\n", s);
    return 0;
}

void entab(char *s, int tabstop)
{
    int i = 0, j = 0, k = 0;
    char *t = (char *)malloc(strlen(s) + 1);
    strcpy_s(s, strlen(t) + 1, t);
    while (t[i] != '\0'){
        if (t[i] == '\t'){
            while (j < tabstop){
                t[k] = ' ';
                k++;
                j++;
            }
            j = 0;
        }else{
            t[k] = t[i];
            k++;
        }
        i++;
    }
    t[k] = '\0';
    strcpy_s(s, strlen(t) + 1, t);
    free(t);
}
void detab(char *s)
{
    int i = 0, k = 0;
    char *t = (char *)malloc(strlen(s) + 1);
    strcpy_s(s, strlen(t) + 1, t);
    while (t[i] != '\0'){
        if (t[i] == ' '){
            while (t[i] == ' '){
                i++;
            }
            t[k] = '\t';
            k++;
        }else{
            t[k] = t[i];
            k++;
        }
        i++;
    }
    t[k] = '\0';
    strcpy_s(s, strlen(t) + 1, t);
    free(t);
}
