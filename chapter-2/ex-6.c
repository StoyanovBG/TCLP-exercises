#include <stdio.h>

unsigned setbits(int x, int p, int n, int y);

int main() 
{
    printf("%d\n", setbits(42, 5, 3, 24));
    return 0;
}

unsigned setbits(int x, int p, int n, int y)
{
    unsigned mask = ~(~0 << n) << (p + 1 - n);
    return (x & ~mask) | ((y << (p + 1 - n)) & mask);
}