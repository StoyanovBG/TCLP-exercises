#include <stdio.h>

float c_to_f(int c);

int main(void)
{
    float c, f;
    int lower = 0, upper = 300, step = 30;

    printf("Cels\t\tFahr\n");

    c = lower;
    while (c <= upper){
        f = c_to_f(c);
        printf("%3.0f\t\t%6.0f\n", c, f);
        c += step;
    }
    return 0;
}

float c_to_f(int c)
{
    return (9.0 / 5.0) * c + 32.0f;
}