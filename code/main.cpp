#include <stdio.h>
#include "tree.h"

int main(void) {
    FILE* fp = fopen("./code/in", "r");
    Tree* tree = NULL;
    int key;
    while (fscanf(fp, "%d", &key) != -1) {
        insert(tree, key);
        reverseOrder(tree);
        printf("\n");
    }
}