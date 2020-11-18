#include <stdio.h>
#include <stdlib.h>
void bracketsNotMatched(void) {
    printf("Error: unmatched brackets\n");
    exit(1);
}
void divideByZeroError(void) {
    printf("Error: divide by zero\n");
    exit(1);
}
void illegalExpression(void) {
    printf("Error: illegal expression\n");
    exit(1);
}
void valueRangeError(void) {
    printf("Error: value range error\n");
    exit(1);
}
void operatorNameError(void) {
    printf("Error: undefined operator\n");
    printf(
        "please use '+' '-' '*' '/' '^' 'sin' 'cos' 'tan' 'cot' 'lg' 'ln' '(' "
        "')'\n");
    exit(1);
}
