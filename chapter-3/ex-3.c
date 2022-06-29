#include <stdio.h>

#define MAX 1000

void expand(char *s1, char *s2);

int main()
{
	char s1[MAX], s2[MAX];
	scanf("%s", s1);
	expand(s1, s2);
	printf("%s\n", s2);
	return 0;
}

void expand(char *s1, char *s2)
{
    int i, j = 0, k;
    char c;
    for (i = 0; (c = s1[i]) != '\0'; i++){
        if (c == '-' && s1[i+1] >= c){
            if (s1[i + 1] == '\0'){
                s2[j++] = c;
            }else{
                for (k = s1[i - 1] + 1; k <= s1[i + 1]; k++){
                    s2[j++] = k;
                }
                i++;
            }
        }else{
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}
