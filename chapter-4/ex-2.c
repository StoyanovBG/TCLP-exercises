#include <stdio.h>
#include<math.h>

double aatof(char s[], double *n);

int main()
{
    char s[] = "123.45e-6";
    double n;
    int i;
    i = aatof(s, &n);
    printf("%s\n", s + i);
    printf("%.6f\n", n);
    return 0;
}

double aatof(char s[], double *n)
{
    int i, sign;
    double t, exp;

    for (i = 0; s[i] == ' '; i++)   ; // skip spaces
    if (s[i] == '+' || s[i] == '-') { // check for sign
        sign = (s[i++] == '+') ? 1 : -1; // set sign
    }else {
        sign = 1; // if no sign, set sign to +
    }
    for (t = 0.0; s[i] >= '0' && s[i] <= '9'; i++) { // collect digits
        t = 10.0 * t + (s[i] - '0'); // convert digit
    }
    if (s[i] == '.') { // collect fraction
        i++; // skip decimal point
    }
    for (; s[i] >= '0' && s[i] <= '9'; i++) { // collect digits
        t = 10.0 * t + (s[i] - '0'); // convert digit
    }
    if (s[i] == 'e' || s[i] == 'E'){ // collect exponent
        i++; // skip 'e'
        if (s[i] == '+' || s[i] == '-') { // check for sign
            sign = (s[i++] == '+') ? 1 : -1; // set sign
        }else{
            sign = 1;
        }
        for (exp = 0.0; s[i] >= '0' && s[i] <= '9'; i++) { // collect digits
            exp = 10.0 * exp + (s[i] - '0');    // convert digit
        }
        t *= pow(10.0, sign * exp); // apply exponent
    }
    *n = t;                        // return value
    return i;                     // return index
}