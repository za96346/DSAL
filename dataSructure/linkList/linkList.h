#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdbool.h>

typedef struct node {
    void *dataPtr;      // 資料位址
    struct node *link;  // 下一個節點位置
} NODE;

typedef struct list {
    int count;   // 總結點數
    NODE *pos;   //
    NODE *head;  // 開始節點
    NODE *rear;  // 最後一個節點
    bool (*addNode)(struct list *pList, void *dataInPtr);
    bool (*removeNode)(struct list *pList, void *keyPtr);

    /**
     * @details 加入一個節點
     * @param pList 串列
     * @param pPre 前一個節點
     * @param dataInPtr 要加入的資料
     */
    bool (*_insert)(struct list *pList, NODE *pPre, void *dataInPtr);

    /**
     * @details 刪除一個節點
     * @param pList 串列
     * @param pPre 前一個節點
     * @param pLoc 要刪除的節點
     */
    bool (*_delete)(struct list *pList, NODE *pPre, NODE *pLoc);

    /**
     * @details 收尋一個節點
     * @param pList 串列
     * @param pPre 前一個節點
     * @param pLoc 要搜尋的節點
     * @param pArgu
     */
    bool (*_search)(struct list *pList, NODE **pPre, NODE **pLoc, void *pArgu);
} LIST;

typedef struct {
    LIST *(*createList)();
    bool (*searchList)(LIST *pList, void *pArgu, void **dataOutPtr);
    bool (*destroyList)(LIST *pList);
    void (*debugList)(LIST *pList);
} LinkListModule;

extern LinkListModule linkList;

#endif
