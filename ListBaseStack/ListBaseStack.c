#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack *pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack *pstack)
{
    if (pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = pstack->head; // 새 노드가 헤드가 가리키는 노드를 가리킴

    pstack->head = newNode;       // 포인터 변수 head가 새 노드를 가리킴
}

Data SPop(Stack *pstack)
{
    Data rdata;
    Node *rnode;

    if (SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(1);
    }
    
    rdata = pstack->head->data;
    rnode = pstack->head;

    pstack->head = pstack->head->next;
    free(rnode);
    return rdata;
}

Data SPeek(Stack *pstack)
{
    if (SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(1);
    }

    return pstack->head->data;
}