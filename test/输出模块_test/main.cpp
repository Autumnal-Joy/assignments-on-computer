#include <stdio.h>
#include "../sources/all.h"
#include "math.h"

int main(void) {
    int n;
    FILE* input = fopen("./input", "r");
    while (1) {
        fscanf(input, "%d", &n);
        if (n == 0)
            break;
        int Y[n];
        for (int i = 0; i < n; i++) {
            fscanf(input, "%d", &Y[i]);
        }
        print_ans(Y, n);
    }
    fclose(input);
}
