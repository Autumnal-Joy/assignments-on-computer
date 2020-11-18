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
        "����: �����������, ���ʽ�ڲ�������ֿո����, "
        "�������ʽ��'='��β\n");
    printf("������ֵ��ַ�:\n");
    printf("    ��Ŀ�����: -(ȡ�෴��), sin, cos, tan, cot, lg, ln\n");
    printf("    ˫Ŀ�����: +, -(����), *, /, ^\n");
    printf("    ���������: (, )\n");
    printf(
        "* ��������������ϴ���, ����������ʵ�����, �� 2^2^4=256, "
        "2^(2^4)=65536\n");
    printf(
        "* sin, cos, tan, cot, lg, ln ����Ҫ�������, �� sin(sin(sin(1)))\n");
}
