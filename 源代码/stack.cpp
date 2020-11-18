#include <stdlib.h>
#include "main.h"

NumNode* createNumNode(double num) {
    NumNode* node = (NumNode*)malloc(sizeof(NumNode));
    node->num = num;
    node->nextNode = NULL;
    return node;
}

OpeNode* createOpeNode(char ope) {
    OpeNode* node = (OpeNode*)malloc(sizeof(OpeNode));
    node->ope = ope;
    node->nextNode = NULL;
    return node;
}

NumNode* createNumStack(void) {
    return createNumNode(0);
}
OpeNode* createOpeStack(void) {
    return createOpeNode(0);
}

void pushNum(NumNode* stack, double num) {
    NumNode* node = createNumNode(num);
    node->nextNode = stack->nextNode;
    stack->nextNode = node;
}

void pushOpe(OpeNode* stack, char ope) {
    OpeNode* node = createOpeNode(ope);
    node->nextNode = stack->nextNode;
    stack->nextNode = node;
}

double popNum(NumNode* stack) {
    NumNode* node = stack->nextNode;
    double ret = 0;
    if (node) {
        ret = node->num;
        stack->nextNode = node->nextNode;
        free(node);
    }
    return ret;
}

char popOpe(OpeNode* stack) {
    OpeNode* node = stack->nextNode;
    char ret = 0;
    if (node) {
        ret = node->ope;
        stack->nextNode = node->nextNode;
        free(node);
    }
    return ret;
}

char isNumStackEmpty(NumNode* stack) {
    return stack->nextNode == NULL;
}

char isOpeStackEmpty(OpeNode* stack) {
    return stack->nextNode == NULL;
}

double topNum(NumNode* stack) {
    NumNode* node = stack->nextNode;
    double ret = 0;
    if (node) {
        ret = node->num;
    }
    return ret;
}

char topOpe(OpeNode* stack) {
    OpeNode* node = stack->nextNode;
    char ret = 0;
    if (node) {
        ret = node->ope;
    }
    return ret;
}

void deleteNumStack(NumNode* stack) {
    while (stack) {
        NumNode* temp = stack->nextNode;
        free(stack);
        stack = temp;
    }
}

void deleteOpeStack(OpeNode* stack) {
    while (stack) {
        OpeNode* temp = stack->nextNode;
        free(stack);
        stack = temp;
    }
}
