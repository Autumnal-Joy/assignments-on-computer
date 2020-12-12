#include <sort.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const* argv[]) {
    FILE* fp = fopen("code/input.in", "r");
    int a = 0, b = 0, i = 0;
    fscanf(fp, "%d", &b);
    int data[b + 1];
    quick(data, a, b);
    threequick(data, a, b);
    return 0;
}