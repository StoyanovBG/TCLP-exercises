#include <stdio.h>
#include <string.h>

void swap(char *array[], int i, int j);
void sort(char *array[], int size, int reverse);

int main(int argc, char *argv[])
{
    int i, reverse = 0, size = 0;
    char *array[100];
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "-n") == 0) {
            reverse = 1;
        }
        else {
            array[size] = argv[i];
            size++;
        }
    }
    sort(array, size, reverse);
    for (i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }
    return 0;
}

void swap(char *array[], int i, int j) {
    char *temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
void sort(char *array[], int size, int reverse) {
    int i, j;
    if (reverse == 0) {
        for (i = 0; i < size - 1; i++) {
            for (j = i + 1; j < size; j++) {
                if (strcmp(array[i], array[j]) > 0) {
                    swap(array, i, j);
                }
            }
        }
    }
    else {
        for (i = 0; i < size - 1; i++) {
            for (j = i + 1; j < size; j++) {
                if (strcmp(array[i], array[j]) < 0) {
                    swap(array, i, j);
                }
            }
        }
    }
}

