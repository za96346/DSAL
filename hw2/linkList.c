#include "linkList.h"

#include <stdio.h>
#include <stdlib.h>

bool _insert(struct list *pList, NODE *pPre, void *dataInPtr) {
    NODE *pNew = (NODE *)malloc(sizeof(NODE));
    if (pNew == NULL) {
        return false;
    }

    (*pNew).dataPtr = dataInPtr;
    (*pNew).link = NULL;

    // 插入首個節點
    if (pPre == NULL) {
        (*pNew).link = (*pList).head;
        (*pList).head = pNew;

        if ((*pList).count == 0) {
            (*pList).rear = pNew;
        }
    } else {
        (*pNew).link = (*pPre).link;
        (*pPre).link = pNew;

        if ((*pNew).link == NULL) {
            (*pList).rear = pNew;
        }
    }

    (*pList).count++;
    return true;
}

bool _delete(struct list *pList, NODE *pPre, NODE *pLoc) {
    // 移動節點
    if (pPre == NULL) {
        // ??
    } else {
        (*pPre).link = (*pLoc).link;
    }

    // 更動最後一個節點
    if ((*pPre).link == NULL) {
        (*pList).rear = pPre;
    }

    (*pList).count--;
    free(pLoc);
    return true;
}

bool _search(struct list *pList, NODE **pPre, NODE **pLoc, void *pArgu) {
    *pPre = NULL;           // 前一個節點
    *pLoc = (*pList).head;  // 當前節點

    while (*pLoc != NULL) {  // 檢查 pLoc 是否為 NULL
        if (pArgu == (*pLoc)->dataPtr) {
            return true;
        }

        *pPre = *pLoc;
        *pLoc = (*pLoc)->link;
    }

    return false;
}

bool addNode(struct list *pList, void *dataInPtr) {

    NODE *pPre;
    NODE *pLoc;

    bool found = _search(pList, &pPre, &pLoc, dataInPtr);

    // 重複新增節點 返回錯誤
    if (found) {
        return false;
    }

    return _insert(pList, pPre, dataInPtr);
}

bool removeNode(struct list *pList, void *keyPtr) {
    NODE *pPre;
    NODE *pLoc;

    bool found = _search(pList, &pPre, &pLoc, keyPtr);
    if (found) {
        _delete(pList, pPre, pLoc);
    }
    return found;
}

LIST *createListImplement() {
    LIST *pList = (LIST *)malloc(sizeof(LIST));
    if (pList == NULL) {
        return NULL;  // 記憶體分配失敗
    }

    // parameters initial
    (*pList).count = 0;
    (*pList).pos = NULL;
    (*pList).head = NULL;
    (*pList).rear = NULL;

    // functions initial
    (*pList).addNode = addNode;
    (*pList).removeNode = removeNode;
    (*pList)._insert = _insert;
    (*pList)._delete = _delete;
    (*pList)._search = _search;

    return pList;
}

bool searchListImplement(LIST *pList, void *pArgu, void **dataOutPtr) {
    return true;
}

bool destroyListImplement(LIST *pList) {
    NODE* deleteNode;
    while ((*pList).head != NULL)
    {
        deleteNode = (*pList).head;
        pList->head = (*pList).head->link;
        // free(deleteNode->dataPtr);
        free(deleteNode);
    }
    free(pList);
    return true;
}

/**
 * @brief 調試串列，打印串列的詳細資訊
 */
void debugListImplement(LIST *pList) {
    if (pList == NULL) {
        printf("List is NULL.\n");
        return;
    }

    printf("=============================================\n");
    printf("List Count: %d\n", pList->count);
    printf("Head Node Address: %p\n", (void *)pList->head);
    if (pList->head != NULL) {
        printf("Head Node DataPtr: %d\n", *(int *)(pList->head->dataPtr));  // 假設 dataPtr 是 int*
    }
    printf("---------------------------------------------\n");
    printf("Rear Node Address: %p\n", (void *)pList->rear);
    if (pList->rear != NULL) {
        printf("Rear Node DataPtr: %d\n", *(int *)(pList->rear->dataPtr));  // 假設 dataPtr 是 int*
    }
    printf("---------------------------------------------\n");

    NODE *currentNode = pList->head;
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

LinkListModule linkList = {
    .createList = createListImplement,
    .searchList = searchListImplement,
    .destroyList = destroyListImplement,
    .debugList = debugListImplement,
};