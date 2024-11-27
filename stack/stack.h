#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct node {
    void *dataPtr;      // 資料位址
    struct node *link;  // 下一個節點位置
} NODE;

typedef struct stack {
    int count;  // 總結點數
    NODE *top;  // 開始節點
    NODE *rear;  // 最後一個節點

    bool (*pushStack) (STACK *stack, void *dataInPtr); // 推入
    bool (*popStack) (STACK *stack); // 取出
    void (*stackTop) (STACK* stack); // 取出第一個元素
    int (*stackCount) (STACK* stack); // 取得堆疊數量
    bool (*isEmptyStack) (STACK* stack); // 是否為 空堆疊
    bool (*isFullStack) (STACK* stack); // 是否為 滿堆疊
} STACK;

typedef struct
{
    STACK *(*createStack) ();
    bool (*destroyStack) (STACK* stack); // 移除堆疊
    void (*debugStack)(STACK *stack); // 偵錯堆疊

    /* data */
} StackModule;

extern StackModule stack;

#endif