#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>

typedef struct node
{
    int value;            // 節點值
    struct node* left;    // 左子樹
    struct node* right;   // 右子樹
    struct node* parent;  // 父節點
} NODE;

typedef struct heap
{
    NODE* root;           // 根節點
    int size;             // 節點數量

    void (*insert)(HEAP* heap, int value);     // 插入元素
    int (*extractMax)(HEAP* heap);             // 提取最大值
    void (*heapifyUp)(NODE* node);             // 向上調整
    void (*heapifyDown)(NODE* node);           // 向下調整
    NODE* (*getLastNode)(HEAP* heap);          // 獲取最後插入的節點
} HEAP;

typedef struct
{
    HEAP *(*createHeap)(); // 創建heap
    bool (*destroyHeap)(HEAP *pHeap); // 移除heap
    void (*debugHeap)(HEAP *pHeap); // 偵錯heap
} HeapModule;



#endif