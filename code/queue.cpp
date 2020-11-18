#include <stdlib.h>
#include "main.h"

void initqueue(queue& s) {
    s.front = NULL;
    s.rear = NULL;
}

void enqueue(queue& s, node* ptr) {
    queueptr qptr = (queueptr)malloc(sizeof(queueNode));
    qptr->next = NULL;
    qptr->data = ptr;
    if (s.rear) {
        s.rear->next = qptr;
    } else {
        s.front = qptr;
    }
    s.rear = qptr;
}

node* dequeue(queue& s) {
    if (!s.front) {
        return NULL;
    }
    node* ret = s.front->data;
    queueptr temp = s.front->next;
    free(s.front);
    s.front = temp;
    if (!s.front) {
        s.rear = NULL;
    }
    return ret;
}

void delqueue(queue& s) {
    while (dequeue(s)) {
        continue;
    }
}