#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq)
{
    pq->front = NULL; 
    pq->rear = NULL;
}

int QIsEmpty(Queue* pq)
{
    if (pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if (QIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        pq->rear->next = newNode; // 마지막 노드가 새 노드를 가리키게 함
        pq->rear = newNode;       // rear가 새 노드를 가리키게 한다.
    }
}

Data Dequeue(Queue *pq)
{
    Node *delNode;
    Data retData;

    if (QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(1);
    }
    delNode = pq->front;
    retData = pq->front->data;
    pq->front = pq->front->next;

    free(delNode);
    return retData;
}

Data QPeek(Queue *pq)
{
    if (QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    return pq->front->data;
}