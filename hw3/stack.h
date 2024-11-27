#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct node {
    void *dataPtr;      // 資料位址
    struct node *link;  // 下一個節點位置
} NODE;

typedef struct stack {
    int count;  // 總結點數
    NODE *head;  // 開始節點
    NODE *rear;  // 最後一個節點
} STACK;

typedef struct
{
    /* data */
} StackModule;

extern StackModule stack;

#endif