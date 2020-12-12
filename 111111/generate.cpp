#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 测试文件数
int T = 1;
int n = 100;

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main(int argc, char const* argv[]) {
    char in[100], out[100];
    int num[30000];
    FILE* fp;
    srand(time(NULL));
    for (int i = 0; i < T; i++) {
        sprintf(in, "%d.in", i);
        sprintf(out, "%d.out", i);
        fp = fopen(in, "w");
        fprintf(fp, "%d\n", n);
        for (int j = 0; j < n; j++) {
            num[j] = rand() % 101207;
            fprintf(fp, "%d ", num[j]);
        }
        fclose(fp);
        qsort(num, n, sizeof(int), cmp);
        fp = fopen(out, "w");
        for (int j = 0; j < n; j++) {
            fprintf(fp, "%d ", num[j]);
        }
        fclose(fp);
    }
    return 0;
}
