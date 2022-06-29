#include <stdio.h>

unsigned int rightrot(unsigned x, int n);

int main()
{
    printf("%d\n", rightrot(43, 3));
    return 0;
}

unsigned int rightrot(unsigned x, int n)
{
    for(int i = 0; i < n; i++){
        x = (x >> 1) | ~(~(0) >> 1);
    }
    return x;
}