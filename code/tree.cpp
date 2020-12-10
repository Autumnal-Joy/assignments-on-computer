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

void balanced(Tree*& tree) {}

void insert(Tree*& tree, int key) {
    if (!tree) {
        tree = createTree(NULL, key);
    } else {
        if (key < tree->key) {
            insert(tree->leftChild, key);
        } else {
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