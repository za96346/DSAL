#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef struct node {
    int *data;
    struct Node* left;
    struct Node* right;
} NODE;

typedef struct tree
{
    NODE* root; // 根節點
    int count; // 節點數

    NODE *(*insertNode)(NODE*pNode, int *data); // 插入
    NODE *(*deleteNode)(NODE*pNode, int *data); // 刪除

    void (*preOrder)(NODE *pNode); // 前序遍歷
    void (*inOrder)(NODE *pNode); // 中序遍歷
    void (*postOrder)(NODE *pNode); // 後續遍歷
} TREE;

typedef struct 
{
    TREE *(*createTree)();
    NODE *(*searchTree)(NODE *pNode, int *data);
    void (*debugTree)(TREE *pTree);
    bool (*destroyTree)(TREE *pTree);
} TreeModule;

extern TreeModule tree;

#endif