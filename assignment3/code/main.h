#if !defined(MAIN_H)
#define MAIN_H

//二叉树结点二叉树结构体
typedef struct node {
    char data;
    struct node* left_child;
    struct node* right_child;
} node;

//队列结点结构体
typedef struct queueNode {
    node* data;
    struct queueNode* next;
} queueNode, *queueptr;

//队列结构体
typedef struct {
    queueptr front;
    queueptr rear;
} queue;

#endif  // MAIN_H
