#ifndef CLB_STACK_H
# define CLB_STACK_H

#define TRUE        1
#define FALSE       0

#include "CLinkedList.h"

typedef struct _CListStack
{
    List *plist;
}CListStack;

typedef CListStack Stack;

void StackInit(Stack *pstack);
int  SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);



#endif