#if !defined(MAIN_H)
#define MAIN_H

// ������ջ�Ľڵ�
typedef struct _num_node {
    // ������
    double num;
    // ��һ���ڵ�
    _num_node* nextNode;
} NumNode;

// ������ջ�Ľڵ�
typedef struct _ope_node {
    // ������
    char ope;
    // ��һ���ڵ�
    _ope_node* nextNode;
} OpeNode;

#endif  // MAIN_H
