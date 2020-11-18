#if !defined(QUEUE_H)
#define QUEUE_H
#include "main.h"

/*
   初始化队列
*/
void initqueue(queue& s);

/*
   将元素压入队列
*/
void enqueue(queue& s, node* ptr);

/*
   出队列
*/
node* dequeue(queue& s);

void delqueue(queue& s);

#endif  // QUEUE_H
