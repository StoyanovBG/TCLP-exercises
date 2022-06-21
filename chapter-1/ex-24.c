#include <stdio.h>

int main()
{
    char c;
    int parentheses = 0 , brackets = 0 , 
        braces = 0 , quotes = 0 , 
        escape = 0 , comment = 0;

    while ((c = getchar()) != EOF){
        if (c == '(')
            parentheses++;
        else if (c == ')')
            parentheses--;
        else if (c == '[')
            brackets++;
        else if (c == ']')
            brackets--;
        else if (c == '{')
            braces++;
        else if (c == '}')
            braces--;
        else if (c == '\"')
            quotes++;
        else if (c == '\'')
            quotes--;
        else if (c == '\\')
            escape++;
        else if (c == '/')
            comment++;
        else if (c == '*')
            comment--;
    }

    if (parentheses != 0)
        printf("Unmatched parentheses\n");
    if (brackets != 0)
        printf("Unmatched brackets\n");
    if (braces != 0)
        printf("Unmatched braces\n");
    if (quotes != 0)
        printf("Unmatched quotes\n");
    if (escape != 0)
        printf("Unmatched escape sequences\n");
    if (comment != 0)
        printf("Unmatched comments\n");

    return 0;
}