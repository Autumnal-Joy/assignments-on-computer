#if !defined(CREATE_H)
#define CREATE_H
#include "main.h"
/*
   输入：数的前序序列数组pre[]，数的中序序列数组in[]
   返回：树的根节点的指针(node *)
   动态申请根节点空间，赋根植，若前序数组中只有一个值，该树只有根节点，
   将根结点的左右孩子均赋为空，返回根节点。在中序序列里找到根节点并记录其位置，
   就可以得到左子树的结点数和右子树的结点数，然后将数组划分为左子树和右子树部分。
   如果左子树为空，则根节点左孩子赋为空，否则继续调用本函数，
   根据左子树的结点数对数组界限进行修改，将返回值赋即左子树的根结点指针赋给根结点的左孩子，并且赋根结点的值给左孩子的父母指针。右边类似。
*/
node* create(char pre[], char in[]);

#endif  // CREATE_H