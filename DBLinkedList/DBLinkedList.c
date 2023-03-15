#include "DBLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List *plist)
{
    plist->head = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    // plist->head = NULL; 인 상태
    newNode->next = plist->head;  // 새 노드의 next를 NULL로 초기화(첫 노드일때만)
    if (plist->head != NULL)
        plist->head->prev = newNode;   // 두 번째 이후의 노드를 추가할 때만 실행
    newNode->prev = NULL;  
    plist->head = newNode;

    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
    if(plist->head == NULL)
        return FALSE;
    
    plist->cur = plist->head;
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, Data *pdata)
{
    if(plist->cur->next == NULL)
        return FALSE;
    
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LPrevious(List *plist, Data *pdata)
{
    if (plist->cur->prev == NULL)
        return FALSE;
    
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return TRUE;
}

int LCount(List *plist)
{
    return plist->numOfData;
}