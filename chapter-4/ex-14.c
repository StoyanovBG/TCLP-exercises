#include <stdio.h>

#define swap(t,x,y) do{t=x;x=y;y=t;}while(0)

int main()
{
    int x=10,y=20;
    int tmp;
    printf("%d %d\n",x,y);
    swap(tmp,x,y);
    printf("%d %d\n",x,y);
    return 0;
}

