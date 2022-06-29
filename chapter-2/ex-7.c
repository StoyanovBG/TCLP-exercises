#include <stdio.h>

unsigned invert(int x, int p, int n);

int main() 
{
    printf("%d\n", invert(42, 5, 3));
    return 0;
}

unsigned invert(int x, int p, int n)
{
    unsigned mask = ~(~0 << n) << (p + 1 - n);
    return x ^ mask;
}