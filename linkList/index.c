#include "linkList.h"
#include <stdio.h>

/**
 * gcc -c linkList.c -o linkList.o
 * gcc -c index.c -o index.o
 * gcc linkList.o index.o -o program
 * ./program
*/

int main() {
    LIST* list = linkList.createList();
    int first = 1;
    int second = 2;
    int third = 3;
    int fourth = 4;
    int fiveth = 5;

    (*list).addNode(list, &first);
    (*list).addNode(list, &second);
    (*list).addNode(list, &third);
    (*list).addNode(list, &fourth);
    (*list).addNode(list, &fiveth);

    // (*list).removeNode(list, &second);

    linkList.debugList(list);

    linkList.destroyList(list);
    linkList.debugList(list);

    printf("list => %p", list);
    return 0;
}