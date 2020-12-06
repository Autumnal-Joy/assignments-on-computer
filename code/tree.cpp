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
void leftRotate(Tree* parent, Tree* rightChild) {}

/* 右顺时针旋转 */
void rightRotate(Tree* parent, Tree* leftChild) {}

/* 从叶子节点开始向上计算平衡因子, 当出现不平衡状态时进行旋转 */
void balanced(Tree* leaf) {}

Tree* insert(Tree* tree, int key) {
    if (!tree) {
        return createTree(NULL, key);
    }
    if (key < tree->key) {
        tree->leftChildHeight++;
        if (tree->leftChild) {
            insert(tree->leftChild, key);
        } else {
            tree->leftChild = createTree(tree, key);
            balanced(tree->leftChild);
        }
    } else {
        tree->rightChildHeight++;
        if (tree->rightChild) {
            insert(tree->rightChild, key);
        } else {
            tree->rightChild = createTree(tree, key);
            balanced(tree->rightChild);
        }
    }
    return tree;
}

void reverseOrder(Tree* tree) {
    if (!tree) {
        return;
    }
    reverseOrder(tree->rightChild);
    printf("%d ", tree->key);
    reverseOrder(tree->leftChild);
}