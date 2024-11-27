#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

bool pushStack (STACK* stack, void* dataInPtr) {
    NODE *newNode = (NODE*) malloc(sizeof(NODE));

    if (!newNode) return false;

    (*newNode).dataPtr = dataInPtr;
    (*newNode).link = (*stack).top;

    (*stack).top = newNode;
    
    (*stack).count ++;
    return true;
}

bool *popStack (STACK *stack) {
    NODE *removeNode = (*stack).top;

    if ((*stack).count == 0) return false;

    free((*stack).top->dataPtr);
    (*stack).top = (*stack).top->link;
    free(removeNode);
    (*stack).count --;

    return true;
}

void *stackTop (STACK *stack) {
    if ((*stack).count == 0) return NULL;
    return (*stack).top->dataPtr;
}

int stackCount (STACK* stack) {
    return (*stack).count;
}

bool isEmptyStack (STACK* stack) {
    return (*stack).count == 0;
}

bool isFullStack (STACK* stack) {
    NODE *newNode = (NODE*) malloc(sizeof(NODE));

    if (!newNode) return true;
    free(newNode);
    return false;
}

STACK *createStackImplement() {
    STACK *stack = (STACK*) malloc(sizeof(STACK));

    if (stack) {
        (*stack).count = 0;
        (*stack).top = NULL;

        (*stack).pushStack = pushStack;
        (*stack).popStack = popStack;
        (*stack).stackTop = stackTop;
        (*stack).stackCount = stackCount;
        (*stack).isEmptyStack = isEmptyStack;
        (*stack).isFullStack = isFullStack;
    }

    return stack;
}

bool destroyStackImplement (STACK *stack) {
    NODE *current;
    
    if (!stack) return false;

    while ((*stack).top != NULL)
    {
        free((*stack).top->dataPtr);
        current = (*stack).top;
        (*stack).top = (*stack).top->link;
        free(current);
    }

    return true;
}

void debugStackImplement(STACK *stack) {
    if (stack == NULL) {
        printf("List is NULL.\n");
        return;
    }

    printf("=============================================\n");
    printf("List Count: %d\n", stack->count);
    printf("Head Node Address: %p\n", (void *)stack->top);
    if (stack->top != NULL) {
        printf("Head Node DataPtr: %d\n", *(int *)(stack->top->dataPtr));  // 假設 dataPtr 是 int*
    }
    printf("---------------------------------------------\n");


    NODE *currentNode = stack->top;
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