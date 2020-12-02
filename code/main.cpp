#include <stdio.h>
#include "tree.h"

int main(void) {
    Tree* tree;
    int val;
    while (1) {
        scanf("%d", &val);
        // 输入负值终止程序
        if (val < 0) {
            break;
        }
        reverseOrder(insert(tree, val));
    }
}