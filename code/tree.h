#if !defined(TREE_H)
#define TREE_H

typedef struct Tree {
    // 左子树
    Tree* leftChild;
    // 右子树
    Tree* rightChild;
    // 父母节点
    Tree* parent;
    // 左子树的高度
    int leftHeight;
    // 右子树的高度
    int rightHeight;
    // 节点保存的数据
    int val;
} Tree;

/* 返回树节点tree的高度. (叶子节点的高度为1) */
int getHeight(Tree* tree);

/* 以parent为父母节点, 以val为节点数据, 创建一个新的节点并返回该节点.
 * (根节点的父母节点为NULL) */
Tree* createTree(Tree* parent, int val);

/* 左逆时针旋转, 更新双向指针的关系以及左右孩子高度 */
void leftRotate(Tree* parent, Tree* rightChild);

/* 右顺时针旋转 */
void rightRotate(Tree* parent, Tree* leftChild);

/* 从叶子节点开始向上计算平衡因子, 当出现不平衡状态时进行旋转 */
void balanced(Tree* leaf);

/* 在平衡二叉树tree中插入一个数值为val的节点, 且插入节点后平衡新树,
 * 返回平衡后的树的根节点. */
Tree* insert(Tree* tree, int val);

/* 逆中序遍历树tree, 以空格分隔关键字, 输出占一行. */
void reverseOrder(Tree* tree);

#endif  // TREE_H
