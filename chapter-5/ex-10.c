#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

unsigned char sp = 0;
double stack[100];

double pop(void);
void push(float element);

int main(int argc, char *argv[])
{
    for (size_t i = 1; i < argc; ++i) {
        double number = atof(argv[i]);
        if (number || strcmp(argv[i], "0") == 0) {
            push(number);
        } else if (strlen(argv[i]) == 1) {
            if (sp >= 2 && sp < 100) {
                double number2 = pop();
                double number1 = pop();
                char op = *argv[i];
                switch (op) {
                    case '+':
                        push(number1 + number2);
                        break;
                    case '-':
                        push(number1 - number2);
                        break;
                    case '*':
                        push(number1 * number2);
                        break;
                    case '/':
                        if (number2 == 0) {
                            printf("Division by zero.\n");
                            return -1;
                        } else {
                            push(number1 / number2);
                        }
                        break;
                    default:
                        printf("Unknown operator: %c\n", op);
                        break;
                }
            }
        }
    }
    printf("%.2f", pop());
    return 0;
}

double pop(void)
{
    if (sp > 0){
        return stack[sp--];
    }
    printf("the stack is empty.\n");
    return 0;
}
void push(float element)
{
    if (sp < 100){
        stack[++sp] = element;
    }else{
        printf("the stack is full.\n");
    }
}
