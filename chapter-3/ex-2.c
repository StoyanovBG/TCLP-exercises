#include <stdio.h>

void escape(char s[], char t[]);
void unscape(char s[], char t[]);

int main()
{
    char s[100];
    char t[100];
    scanf("%s", t);
    escape(s, t);
    printf("%s\n", s);
    unscape(s, t);
    printf("%s", s);
    return 0;
}

void escape(char s[], char t[]) 
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\b':
                s[j++] = '\\';
                s[j++] = 'b';
                break;
            case '\f':
                s[j++] = '\\';
                s[j++] = 'f';
                break;
            case '\a':
                s[j++] = '\\';
                s[j++] = 'a';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unscape(char s[], char t[]) 
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; ++i) {
        if (t[i] == '\\') {
            switch (t[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                case 'b':
                    s[j++] = '\b';
                    break;
                case 'f':
                    s[j++] = '\f';
                    break;
                case 'a':
                    s[j++] = '\a';
                    break;
                default:
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}
