#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "exception.h"
#include "main.h"
#include "stack.h"

static void preProcess(char* pstr);
static char nextOneIsNum(char* pstr, char* nextOpe, double* nextNum);
static int checkPriority(char ope);
static char getType(char* p);
static double getValue(char ope, NumNode* numStack);

double calculate(char* pstr) {
    preProcess(pstr);
    NumNode* numStack = createNumStack();
    OpeNode* opeStack = createOpeStack();
    char nextOpe = 0;
    double nextNum = 0;
    char isNum = 0;
    char firstBracket = 0;
    while (1) {
        isNum = nextOneIsNum(pstr, &nextOpe, &nextNum);
        if (firstBracket) {
            if (nextOpe == '+' || nextOpe == '-' || nextOpe == '*' ||
                nextOpe == '/' || nextOpe == '^' || nextOpe == ')') {
                illegalExpression();
            }
        }
        firstBracket = 0;
        if (isNum) {
            pushNum(numStack, nextNum);
            continue;
        }
        if (nextOpe == '(') {
            pushOpe(opeStack, nextOpe);
            firstBracket = 1;
        } else if (nextOpe == ')') {
            char ope;
            int num1 = 0, num2 = 0;
            while (1) {
                if (isOpeStackEmpty(opeStack)) {
                    illegalExpression();
                }
                ope = popOpe(opeStack);
                if (ope == '(') {
                    break;
                }
                pushNum(numStack, getValue(ope, numStack));
            }
        } else if (nextOpe != 0) {
            while (!isOpeStackEmpty(opeStack) &&
                   checkPriority(nextOpe) <= checkPriority(topOpe(opeStack))) {
                pushNum(numStack, getValue(popOpe(opeStack), numStack));
            }
            if (nextOpe == '=') {
                break;
            }
            pushOpe(opeStack, nextOpe);
        } else {
            operatorNameError();
        }
    }
    if (isNumStackEmpty(numStack)) {
        illegalExpression();
    }
    double ret = popNum(numStack);
    if (!isNumStackEmpty(numStack)) {
        illegalExpression();
    }
    deleteNumStack(numStack);
    deleteOpeStack(opeStack);
    return ret;
}

static void preProcess(char* pstr) {
    int i = 0;
    int flag = 1;
    while (pstr[i]) {
        if (pstr[i] == '(') {
            flag = 1;
        } else if (flag && pstr[i] == '-') {
            pstr[i] = '~';
        } else if (flag && pstr[i] == '+') {
            pstr[i] = ' ';
        } else if (pstr[i] != ' ' && pstr[i] != '\n') {
            flag = 0;
        }
        ++i;
    }
}
static char nextOneIsNum(char* pstr, char* nextOpe, double* nextNum) {
    static int loc = 0;
    char ret;
    while (pstr[loc] == ' ' || pstr[loc] == '\n') {
        loc++;
    }
    if (isdigit(pstr[loc])) {
        ret = 1;
        *nextNum = atof(pstr + loc);
        while (isdigit(pstr[loc]) || pstr[loc] == '.') {
            loc++;
        }
    } else {
        ret = 0;
        *nextOpe = getType(pstr + loc);
        switch (*nextOpe) {
            case 's':
            case 'c':
            case 't':
            case 'o':
                loc++;
            case 'g':
            case 'n':
                loc++;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case '(':
            case ')':
            case '~':
                loc++;
                break;
            case '=':
                loc = 0;
                break;
            default:
                operatorNameError();
        }
    }
    return ret;
}

static int checkPriority(char ope) {
    if (ope == '(' || ope == '=') {
        return 0;
    } else if (ope == '+' || ope == '-') {
        return 1;
    } else if (ope == '*' || ope == '/' || ope == '~') {
        return 2;
    } else if (ope == '^') {
        return 3;
    } else {
        return 4;
    }
}

static char getType(char* p) {
    switch (*p) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '~':
        case '(':
        case ')':
            return *p;
        case '\0':
            return '=';
        default:
            if (*p == 0 || *(p + 1) == 0) {
                return 0;
            } else if (*p == 'l' && *(p + 1) == 'n') {
                return 'n';
            } else if (*p == 'l' && *(p + 1) == 'g') {
                return 'g';
            } else if (*(p + 2) == 0) {
                return 0;
            } else if (*p == 's' && *(p + 1) == 'i' && *(p + 2) == 'n') {
                return 's';
            } else if (*p == 'c' && *(p + 1) == 'o' && *(p + 2) == 's') {
                return 'c';
            } else if (*p == 't' && *(p + 1) == 'a' && *(p + 2) == 'n') {
                return 't';
            } else if (*p == 'c' && *(p + 1) == 'o' && *(p + 2) == 't') {
                return 'o';
            } else {
                return 0;
            }
    }
}

static double getValue(char ope, NumNode* numStack) {
    double num1 = 0, num2 = 0;
    if (isNumStackEmpty(numStack)) {
        illegalExpression();
    }
    num1 = popNum(numStack);
    if (ope == '+' || ope == '-' || ope == '*' || ope == '/' || ope == '^') {
        if (isNumStackEmpty(numStack)) {
            illegalExpression();
        }
        num2 = popNum(numStack);
    }
    double ans = 0;
    switch (ope) {
        case '+':
            ans = num2 + num1;
            break;
        case '-':
            ans = num2 - num1;
            break;
        case '*':
            ans = num2 * num1;
            break;
        case '/':
            if (fabs(num1) < 1e-6) {
                divideByZeroError();
            }
            ans = num2 / num1;
            break;
        case '^':
            if (fabs(num2) < 1e-6 && fabs(num1) < 1e-6) {
                valueRangeError();
            }
            ans = pow(num2, num1);
            break;
        case 's':
            ans = sin(num1);
            break;
        case 'c':
            ans = cos(num1);
            break;
        case 't':
            if (fabs(cos(num1)) < 1e-6) {
                valueRangeError();
            }
            ans = sin(num1) / cos(num1);
            break;
        case 'o':
            if (fabs(sin(num1)) < 1e-6) {
                valueRangeError();
            }
            ans = cos(num1) / sin(num1);
            break;
        case 'g':
            if (num1 < 1e-6) {
                valueRangeError();
            }
            ans = log10(num1);
            break;
        case 'n':
            if (num1 < 1e-6) {
                valueRangeError();
            }
            ans = log(num1);
            break;
        case '~':
            ans = -num1;
    }
    return ans;
}
