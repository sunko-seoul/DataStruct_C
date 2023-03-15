#ifndef DB_LINKED_LIST_H
# define DB_LINKED_LIST_H

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node *next;
    struct _node *prev;
}Node;

typedef struct _DLinkedList
{
    Node *head;
    Node *cur;
    int  numOfData;
}DBLinkedList;

typedef DBLinkedList List;

void ListInit(List *plist);
void LInsert(List *list, Data data);

int LFirst(List *list, Data *pdata);
int LNext(List *list, Data *pdata);
int LPrevious(List *plist, Data *pdata);
int LCount(List *plist);

#endif