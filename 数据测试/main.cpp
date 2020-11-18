#include <stdio.h>
#include "calculate.h"
#include "input.h"

void info(void);

int main(void) {
    info();
    while (1) {
        char input[100];
        getUserInput(input);
        double ans = calculate(input);
        printf("%f\n", ans);
    }
    return 0;
}

void info(void) {
    printf("encoding: GBK\n");
    printf(
        "输入: 允许多行输入, 表达式内部允许出现空格或换行, "
        "单个表达式以'='结尾\n");
    printf("允许出现的字符:\n");
    printf("    单目运算符: -(取相反数), sin, cos, tan, cot, lg, ln\n");
    printf("    双目运算符: +, -(减号), *, /, ^\n");
    printf("    特殊运算符: (, )\n");
    printf(
        "* 运算符都按照左结合处理, 请自行添加适当括号, 如 2^2^4=256, "
        "2^(2^4)=65536\n");
    printf(
        "* sin, cos, tan, cot, lg, ln 后需要添加括号, 如 sin(sin(sin(1)))\n");
}
