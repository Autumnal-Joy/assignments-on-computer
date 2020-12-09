#include <stdio.h>
#include <stdlib.h>

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
void leftRotate(Tree*& tree) {}

/* 右顺时针旋转, 更新双向指针的关系以及左右孩子高度 */
void rightRotate(Tree*& tree) {}

void balanced(Tree*& tree) {
    int left = tree->leftChildHeight;
    int right = tree->rightChildHeight;
    if (left - right == 2) {
        int left = tree->leftChild->leftChildHeight;
        int right = tree->leftChild->rightChildHeight;
        if (left - right == 1) {
            // LL
            rightRotate(tree);
        } else if (left - right == -1) {
            // LR
            leftRotate(tree->leftChild);
            rightRotate(tree);
        }
    } else if (left - right == -2) {
        int left = tree->rightChild->leftChildHeight;
        int right = tree->rightChild->rightChildHeight;
        if (left - right == -1) {
            // RR
            leftRotate(tree);
        } else if (left - right == 1) {
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
            tree->leftChildHeight++;
            insert(tree->leftChild, key);
        } else {
            tree->rightChildHeight++;
            insert(tree->rightChild, key);
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