#include <stdio.h>

int main(void)
{
    int histogram[100];
    int h_length = 0, word_count = 0;

    for (int i = 0; i < 100; ++i){
        histogram[i] = 0;
    }

    char c;
    int word_index = 0;
    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n') {
            if (word_index > 0) {
                ++histogram[word_index - 1];

                if (histogram[word_index - 1] > word_count) {
                    word_count = histogram[word_index - 1];
                }
                if (h_length < word_index - 1) {
                    h_length = word_index - 1;
                }
                word_index = 0;
            }
        } else{
            ++word_index;
        }
    }

    histogram[h_length + 1] = '#';
    putchar('\n');

    int column_index = 0, line_index = 0;

    for (line_index = word_count; line_index >= 0; --line_index){
        column_index = 0;
        while (histogram[column_index] != '#'){
            if (line_index == 0){
                printf("%2d ", column_index + 1);
            }
            else if (histogram[column_index] >= line_index){
               printf(" * ");
            }
            else{
                printf("   ");
            }
            ++column_index;
        }
        putchar('\n');
    }
    return 0;
}