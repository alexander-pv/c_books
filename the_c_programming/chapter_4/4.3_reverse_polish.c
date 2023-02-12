
#include <stdio.h>
#include <stdlib.h>

#define MAX_OP 100  /* максимальный размер операнда или знака */
#define NUMBER '0'  /* сигнал, что обнаружено число */

// Получить очередное число или знак операции
int getop(char *stack);
// Добавить в стек число
void push(double number);
// Извлечь значение из стека
double pop(void);


int main(int argc, char *argv) {

    int type;
    double op2;
    char str[MAXOP];

    if (argc > 1) {
        while ( (type = getop(s)) != EOF) {

            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;

                case '+':
                    push(pop() + pop());
                    break;

                case '*':
                    push(pop() * pop());
                    break;

                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;

                case '/':
                    op2 = pop();
                    if (op2 != 0.0) {
                        push(pop() / op2);
                    }
                    else {
                        printf("\nZeroDivision Error");
                    }
                    break;

                case '\n':
                    printf("\nResult: %.5f", pop());
                    break

                default:
                    printf("\nUnknownCommand Error: %s", s);
                    break;
            }

        }

    }

}