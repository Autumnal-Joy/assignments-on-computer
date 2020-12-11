#include <stdio.h>
#include <string.h>
#include "../code/tree.h"

int main(int argc, char const* argv[]) {
    FILE* fp = fopen("test/test.in", "r");
    Tree* tree = NULL;
    int key;
    while (fscanf(fp, "%d", &key) != -1) {
        insert(tree, key);
        reverseOrder(tree);
        printf("\n");
    }
    return 0;
}

int equal(Tree* a, Tree* b) {
    if (!a || !b) {
        return a == b;
    }
    if (a->key != b->key || a->leftChildHeight != b->leftChildHeight ||
        a->rightChildHeight != b->rightChildHeight) {
        return 0;
    } else {
        return equal(a->leftChild, b->leftChild) &&
               equal(a->rightChild, b->rightChild);
    }
}