#include <stdio.h>

/*
 * rightmost 1-bit in x is the rightmost 1-bit in x-1
 * x &= (x-1) deletes the rightmost 1-bit in x.
 */

int bitcount(unsigned x);

int main()
{
    printf("%d\n", bitcount(8));
    return 0;
}

int bitcount(unsigned x)
{
    int count = 0;
    while (x){
        x &= (x-1);
        count++;
    }
    return count;
}