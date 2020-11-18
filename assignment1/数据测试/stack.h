#if !defined(STACK_H)
#define STACK_H
#include "main.h"

NumNode* createNumStack(void);
OpeNode* createOpeStack(void);
NumNode* createNumNode(double num);
OpeNode* createOpeNode(char ope);
void pushOpe(OpeNode* stack, char ope);
void pushNum(NumNode* stack, double num);
char isNumStackEmpty(NumNode* stack);
char isOpeStackEmpty(OpeNode* stack);
double popNum(NumNode* stack);
char popOpe(OpeNode* stack);
double topNum(NumNode* stack);
char topOpe(OpeNode* stack);
void deleteNumStack(NumNode* stack);
void deleteOpeStack(OpeNode* stack);

#endif  // STACK_H
