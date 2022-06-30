#include <stdio.h>
#include <string.h>

int strrindex(char *s, char *t);

int main()
{
    char *s = "abcdefghijklmnopqrstuvwxyz";
    char *t = "mno";
    printf("%d\n", strrindex(s, t));
    return 0;
}

int strrindex(char *s, char *t)
{
    int i, j, k, l, count = 0;
    int n = strlen(s);
    int m = strlen(t);

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (s[i + j] != t[j]){
                break;
            }
        }
        if (j == m){
            count++;
        }
    }
    if (count == 0){
        return -1;
    }else{
        for (k = 0; k < n; k++){
            for (l = 0; l < m; l++){
                if (s[k + l] != t[l]){
                    break;
                }
            }
            if (l == m){
                return k;
            }
        }
    }
}