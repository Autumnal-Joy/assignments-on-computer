#if !defined(MAIN_H)
#define MAIN_H

// 操作数栈的节点
typedef struct _num_node {
    // 操作数
    double num;
    // 下一个节点
    _num_node* nextNode;
} NumNode;

// 操作符栈的节点
typedef struct _ope_node {
    // 操作符
    char ope;
    // 下一个节点
    _ope_node* nextNode;
} OpeNode;

#endif  // MAIN_H
