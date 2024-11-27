#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct node {
    void *dataPtr;      // 資料位址
    struct node *link;  // 下一個節點位置
} NODE;

typedef struct queue
{
    int count;  // 總結點數
    NODE *top;  // 開始節點
    NODE *rear;  // 最後一個節點

    bool (*enqueue) (struct queue *pQueue, void *dataInPtr); // 推入
    bool (*dequeue) (struct queue *pQueue); // 取出
    void *(*queueTop) (struct queue* pQueue); // 取出第一個元素
    void *(*queueLast) (struct queue* pQueue); // 取出最後一個元素
    int (*queueCount) (struct queue* pQueue); // 取得佇列數量
    bool (*isEmptyQueue) (struct queue* pQueue); // 是否為 空佇列
    bool (*isFullQueue) (struct queue* pQueue); // 是否為 滿佇列

} QUEUE;

typedef struct
{
    QUEUE *(*createQueue) ();
    bool (*destroyQueue) (QUEUE* pQueue); // 移除佇列
    void (*debugQueue) (QUEUE* pQueue); // 偵錯佇列
    /* data */
} QueueModule;

extern QueueModule queue;

#endif