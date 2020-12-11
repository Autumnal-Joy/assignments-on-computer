#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

typedef struct Tree {
    Tree* leftChild;
    Tree* rightChild;
    Tree* parent;
    int leftChildHeight;
    int rightChildHeight;
    int key;
} Tree;

Tree* createTree(Tree* parent, int key) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->leftChild = NULL;
    tree->rightChild = NULL;
    tree->parent = parent;
    tree->leftChildHeight = 0;
    tree->rightChildHeight = 0;
    tree->key = key;
    return tree;
}

/* 左逆时针旋转, 更新双向指针的关系以及左右孩子高度 */
void leftRotate(Tree*& tree) {
    Tree *A, *C, *D, *P;
    A = tree;
    C = tree->rightChild;
    D = tree->rightChild->leftChild;
    P = tree->parent;
    tree = C;
    C->parent = P;
    if (P->rightChild == A) {
        P->rightChild = C;
    } else {
        P->leftChild = C;
    }
    C->leftChild = A;
    A->rightChild = D;
    D->parent = A;
    A->parent = C;
    int ALH = A->leftChildHeight;
    A->leftChildHeight = C->rightChildHeight;
    C->rightChildHeight = P->leftChildHeight;
    P->leftChildHeight = ALH;
}

/* 右顺时针旋转, 更新双向指针的关系以及左右孩子高度 */
void rightRotate(Tree*& tree) {
    Tree *A, *B, *E, *P;
    A = tree;
    B = tree->leftChild;
    E = tree->leftChild->rightChild;
    P = tree->parent;
    tree = B;
    B->parent = P;
    if (P->leftChild == A) {
        P->leftChild = B;
    } else {
        P->rightChild = B;
    }
    B->rightChild = A;
    A->leftChild = E;
    E->parent = A;
    A->parent = B;
    int ALH = A->leftChildHeight;
    A->leftChildHeight = B->rightChildHeight;
    B->rightChildHeight = P->leftChildHeight;
    P->leftChildHeight = ALH;
}

void balanced(Tree*& tree) {
    int left = tree->leftChildHeight;
    int right = tree->rightChildHeight;
    if (left - right == 2) {
        int left = tree->leftChild->leftChildHeight;
        int right = tree->leftChild->rightChildHeight;
        if (left - right > 0) {
            // LL
            rightRotate(tree);
        } else {
            // LR
            leftRotate(tree->leftChild);
            rightRotate(tree);
        }
    } else if (left - right == -2) {
        int left = tree->rightChild->leftChildHeight;
        int right = tree->rightChild->rightChildHeight;
        if (left - right < 0) {
            // RR
            leftRotate(tree);
        } else {
            // RL
            rightRotate(tree->rightChild);
            leftRotate(tree);
        }
    }
}

void insert(Tree*& tree, int key) {
    if (!tree) {
        tree = createTree(NULL, key);
    } else {
        if (key < tree->key) {
            insert(tree->leftChild, key);
            tree->leftChildHeight = max(tree->leftChild->leftChildHeight,
                                        tree->leftChild->rightChildHeight) +
                                    1;
        } else {
            insert(tree->rightChild, key);
            tree->rightChildHeight = max(tree->rightChild->leftChildHeight,
                                         tree->rightChild->rightChildHeight) +
                                     1;
        }
        balanced(tree);
    }
}

void reverseOrder(Tree* tree) {
    if (!tree) {
        return;
    }
    reverseOrder(tree->rightChild);
    printf("%d ", tree->key);
    reverseOrder(tree->leftChild);
}