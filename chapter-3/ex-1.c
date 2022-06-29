#include <stdio.h>
#include <time.h>

int binsearch(int x, int *v, int n);
int binsearch_new(int x, int *v, int n);
void test(int binsearch(int x, int *v, int n), int x, int *v, int n);

int main(void)
{
    int v[70000];
    int n = 70000;
    int x = 643;
    printf("Original: ");
    test(binsearch, x, v, n);
    printf("New: ");
    test(binsearch_new, x, v, n);
    return 0;
}

int binsearch(int x, int *v, int n)
{
    int low, mid, high;
    low = 0;
    high = n - 1;
    while (low <= high){
        mid = (low + high) / 2;
        if (x < v[mid]){
            high = mid - 1;
        } else if (x > v[mid]){
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binsearch_new(int x, int *v, int n)
{
    int low, mid, high;
    low = 0;
    high = n - 1;
    while (low <= high){
        mid = (low + high) / 2;
        if (x < v[mid]){
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    if (x == v[low - 1]){
        return low - 1;
    }
    return -1;
}

void test(int binsearch(int x, int *v, int n), int x, int *v, int n)
{
    int result;
    clock_t start, end;
    double time;
    start = clock();
    for (int i = 0; i < 70000; ++i){
        result = binsearch(x, v, n);
    }
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.4f\n", time);
}
