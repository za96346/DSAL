#include "stack.h"
#include <stdio.h>

/**
 * gcc -c linkList.c -o linkList.o
 * gcc -c index.c -o index.o
 * gcc linkList.o index.o -o program
 * ./program
*/

int main() {
    int first = 1;
    int second = 2;
    int third = 3;
    int fourth = 4;
    int fiveth = 5;

    STACK *stackInstance = stack.createStack();
    (*stackInstance).pushStack(stackInstance, &first);
    (*stackInstance).pushStack(stackInstance, &second);
    (*stackInstance).pushStack(stackInstance, &third);
    (*stackInstance).pushStack(stackInstance, &fourth);
    (*stackInstance).pushStack(stackInstance, &fiveth);

    stack.debugStack(stackInstance);

    return 0;
}