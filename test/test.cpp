#include <stdio.h>
#include <string.h>
#include "../code/tree.h"
int max(int a, int b);

int getHeight(Tree* tree) {
    if (!tree) {
        return 0;
    }
    return max(getHeight(tree->leftChild), getHeight(tree->rightChild)) + 1;
}

int isBalance(Tree* tree) {
    if (!tree) {
        return 1;
    }
    int l = getHeight(tree->leftChild);
    int r = getHeight(tree->rightChild);
    if (l - r < -1 || l - r > 1) {
        return 0;
    }
    return isBalance(tree->leftChild) && isBalance(tree->rightChild);
}

void inorder(Tree* tree) {
    if (!tree)
        return;
    inorder(tree->leftChild);
    printf("%d ", tree->key);
    inorder(tree->rightChild);
}

int main(int argc, char const* argv[]) {
    FILE* fp = fopen("./test/0.in", "r");
    Tree* tree = NULL;
    int n, num;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &num);
        insert(tree, num);
    }
    printf("%d\n", isBalance(tree));
    inorder(tree);
    return 0;
}