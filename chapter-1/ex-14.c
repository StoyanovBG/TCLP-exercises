#include <stdio.h>

#define ALPHABET 26
#define NUMBERS 10

int main(void)
{
    int i;
    char arr[ALPHABET + NUMBERS];

    for (i = 0; i < (ALPHABET + NUMBERS); ++i){
        arr[i] = 0;
    }

    char c;
    while ((c = getchar()) != EOF){
        if (c >= 'a' && c <= 'z'){
            ++arr[c - 'a'];
        }
        else if (c>= 'A' && c <= 'Z'){
            ++arr[c - 'A'];
        }
        else if (c >= '0' && c <= '9'){
            ++arr[c - '0' + ALPHABET];
        }
    }

    for (i = 0; i < (ALPHABET + NUMBERS); ++i){
        if (i < ALPHABET){
            printf("%c| ", 'A' + i);
        }
        else if (i >= ALPHABET) {
            printf("%c| ", '0' + i - ALPHABET);
        }

        for (int j = 0; j < arr[i]; ++j){
            printf("*");
        }
        putchar('\n');
    }
    return 0;
}