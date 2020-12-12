#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sort.h"

int main(int argc, char const* argv[]) {
    FILE* fp = stdin;
    fp = fopen("code/input.in", "r");
    int n;
    fscanf(fp, "%d", &n);
    int data1[n];
    int data2[n];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &data1[i]);
        data2[i] = data1[i];
    }
    long start, end;
    start = clock();
    quick(data1, 0, n);
    end = clock();
    printf("%f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    threequick(data2, 0, n);
    end = clock();
    printf("%f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}