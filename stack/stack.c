#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

bool pushStack (STACK* pStack, void* dataInPtr) {
    NODE *newNode = (NODE*) malloc(sizeof(NODE));

    if (!newNode) return false;

    (*newNode).dataPtr = dataInPtr;
    (*newNode).link = (*pStack).top;

    (*pStack).top = newNode;
    
    (*pStack).count ++;
    return true;
}

bool popStack (STACK *pStack) {
    NODE *removeNode = (*pStack).top;

    if ((*pStack).count == 0) return false;

    free((*pStack).top->dataPtr);
    (*pStack).top = (*pStack).top->link;
    free(removeNode);
    (*pStack).count --;

    return true;
}

void *stackTop (STACK *pStack) {
    if ((*pStack).count == 0) return NULL;
    return (*pStack).top->dataPtr;
}

int stackCount (STACK* pStack) {
    return (*pStack).count;
}

bool isEmptyStack (STACK* pStack) {
    return (*pStack).count == 0;
}

bool isFullStack (STACK* pStack) {
    NODE *newNode = (NODE*) malloc(sizeof(NODE));

    if (!newNode) return true;
    free(newNode);
    return false;
}

STACK *createStackImplement() {
    STACK *newStack = (STACK*) malloc(sizeof(STACK));

    if (newStack) {
        (*newStack).count = 0;
        (*newStack).top = NULL;

        (*newStack).pushStack = pushStack;
        (*newStack).popStack = popStack;
        (*newStack).stackTop = stackTop;
        (*newStack).stackCount = stackCount;
        (*newStack).isEmptyStack = isEmptyStack;
        (*newStack).isFullStack = isFullStack;
    }

    return newStack;
}

bool destroyStackImplement (STACK *pStack) {
    NODE *current;
    
    if (!pStack) return false;

    while ((*pStack).top != NULL)
    {
        free((*pStack).top->dataPtr);
        current = (*pStack).top;
        (*pStack).top = (*pStack).top->link;
        free(current);
    }

    return true;
}

void debugStackImplement(STACK *pStack) {
    if (pStack == NULL) {
        printf("List is NULL.\n");
        return;
    }

    printf("=============================================\n");
    printf("List Count: %d\n", pStack->count);
    printf("Head Node Address: %p\n", (void *)pStack->top);
    if (pStack->top != NULL) {
        printf("Head Node DataPtr: %d\n", *(int *)(pStack->top->dataPtr));  // 假設 dataPtr 是 int*
    }
    printf("---------------------------------------------\n");


    NODE *currentNode = pStack->top;
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

StackModule stack = {
    .createStack = createStackImplement,
    .destroyStack = destroyStackImplement,
    .debugStack = debugStackImplement
};