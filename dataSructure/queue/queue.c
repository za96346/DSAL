#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @todo enqueue
*/
bool enqueue (struct queue *pQueue, void *dataInPtr) {
    NODE *newNode = (NODE*) malloc(sizeof(NODE));

    if (!newNode) return false;

    (*newNode).dataPtr = dataInPtr;
    (*newNode).link = NULL;

    if ((*pQueue).isEmptyQueue(pQueue)) {
        (*pQueue).top = newNode;
        (*pQueue).rear = newNode;
    } else {
        (*pQueue).rear->link = newNode;
        (*pQueue).rear = newNode;
    }
    
    (*pQueue).count ++;

    return true;
}
bool dequeue (struct queue *pQueue) {
    if ((*pQueue).isEmptyQueue(pQueue)) {
        return false;
    }

    NODE *temp = (*pQueue).top;
    (*pQueue).top = (*pQueue).top->link;
    if ((*pQueue).top == NULL) (*pQueue).rear = NULL;
    free(temp);

    (*pQueue).count --;
    return true;
}
void *queueTop (struct queue* pQueue) {
    return (*pQueue).top;
}
void *queueLast (struct queue* pQueue) {
    return (*pQueue).rear;
}
int queueCount (struct queue* pQueue) {
    return (*pQueue).count;
}
bool isEmptyQueue (struct queue* pQueue) {
    return (*pQueue).count == 0;
}
bool isFullQueue (struct queue* pQueue) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));

    if (newNode) {
        free(newNode);
        return false;
    }

    return true;
}

QUEUE *createQueueImplement () {
    QUEUE *newQueue = (QUEUE*)malloc(sizeof(QUEUE));

    if (newQueue) {
        (*newQueue).count = 0;
        (*newQueue).top = NULL;
        (*newQueue).rear = NULL;

        (*newQueue).enqueue = enqueue;
        (*newQueue).dequeue = dequeue;
        (*newQueue).queueTop = queueTop;
        (*newQueue).queueLast = queueLast;
        (*newQueue).queueCount = queueCount;
        (*newQueue).isEmptyQueue = isEmptyQueue;
        (*newQueue).isFullQueue = isFullQueue;
    }
    
    return newQueue;
}

bool destroyQueueImplement (QUEUE* pQueue) {
    NODE *current;

    if (!pQueue) return false;

    while ((*pQueue).top != NULL) {
        free((*pQueue).top->dataPtr);
        current = (*pQueue).top;
        (*pQueue).top = (*pQueue).top->link;
        free(current);
    }

    return true;
}

void debugQueueImplement (QUEUE* pQueue) {
    if (pQueue == NULL) {
        printf("List is NULL.\n");
        return;
    }

    printf("=============================================\n");
    printf("List Count: %d\n", pQueue->count);
    printf("Head Node Address: %p\n", (void *)pQueue->top);
    if (pQueue->top != NULL) {
        printf("Head Node DataPtr: %d\n", *(int *)(pQueue->top->dataPtr));  // 假設 dataPtr 是 int*
    }
    printf("---------------------------------------------\n");


    NODE *currentNode = pQueue->top;
    int nodeIndex = 0;

    while (currentNode != NULL) {
        printf("Node %d:\n", nodeIndex);
        printf("  Data: %d\n", *(int *)(currentNode->dataPtr));  // 假設 dataPtr 是 int*
        printf("  Link: %p\n", (void *)currentNode->link);
        printf("---------------------------------------------\n");
        currentNode = currentNode->link;
        nodeIndex++;
    }

    printf("=============================================\n");
}

QueueModule queue = {
    .createQueue = createQueueImplement,
    .destroyQueue = destroyQueueImplement,
    .debugQueue = debugQueueImplement,
};