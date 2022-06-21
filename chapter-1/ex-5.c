#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius \t Fahr\n");

    for(celsius = upper; celsius >= lower; celsius = celsius - step){
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f\t\t%6.1f\n", celsius, fahr);
    }
    return 0;
}