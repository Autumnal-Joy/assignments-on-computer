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
    int num[10] = {1, 4, 7, 0, 3, 6, 9, 2, 5, 8};
    Tree* tree = NULL;
    for (int i = 0; i < 10; i++) {
        insert(tree, num[i]);
    }
    printf("%d\n", isBalance(tree));
    inorder(tree);
    return 0;
}