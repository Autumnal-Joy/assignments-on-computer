#include <stdio.h>
#include <string.h>
#include <time.h>
#include "sort.h"

int data1[30000];
int data2[30000];

int main(int argc, char const* argv[]) {
    FILE* fp = stdin;
    fp = fopen("code/0.in", "r");
    int n;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &data1[i]);
        data2[i] = data1[i];
    }
    long start, end;
    start = clock();
    quick(data1, 0, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", data1[i]);
    }
    putchar('\n');

    end = clock();
    printf("quick: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    threequick(data2, 0, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", data2[i]);
    }
    putchar('\n');
    end = clock();
    printf("threequick: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}