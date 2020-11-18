#include <stdio.h>
#include "../sources/all.h"
#include "math.h"

int main(void) {
    int n;
    fclose(fopen("./output", "w"));
    FILE* input = fopen("./input", "r");
    while (1) {
        fscanf(input, "%d", &n);
        if (n == 0)
            break;
        int Y[n];
        int X;
        for (int i = 0; i < n; i++) {
            fscanf(input, "%d", &Y[i]);
        }
        fscanf(input, "%d", &X);
        FILE* output = fopen("output", "a");
        fprintf(output, "%d\n", judge(Y, X));
        fclose(output);
    }
    fclose(input);
}
