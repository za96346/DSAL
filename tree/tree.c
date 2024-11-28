#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

NODE *createNode(int *data) {
    NODE *newNode = (NODE*)malloc(sizeof(NODE));

    if (newNode) {
        (*newNode).data = data;
        (*newNode).left = NULL;
        (*newNode).right = NULL;
    }

    return newNode;
}

NODE *insertNode(NODE*pNode, int *data) {
    if (pNode == NULL) {
        return createNode(data);
    }

    // 遞迴插入
    if (*(*pNode).data > *data) {
        (*pNode).left = insertNode((*pNode).left, data);
    } else {
        (*pNode).right = insertNode((*pNode).right, data);
    }

    return pNode;
}
NODE *findLeftMax(NODE *pNode) {

}
NODE *findRightMin(NODE *pNode) {

}
NODE *deleteNode(NODE*pNode, int *data) {
    if (pNode == NULL) return NULL;

    // 遞迴刪除
    if (*(*pNode).data > *data) {
        (*pNode).left = deleteNode((*pNode).left, data);
    } else if (*(*pNode).data < *data) {
        (*pNode).right = deleteNode((*pNode).right, data);
    } else if (*(*pNode).data == *data) {
        // @todo
    }
}

void preOrder(NODE *pNode){} // 前序遍歷
void inOrder(NODE *pNode){} // 中序遍歷
void postOrder(NODE *pNode){} // 後續遍歷

TREE *createTreeImplement() {
    TREE *newTree = (TREE*)malloc(sizeof(TREE));

    if (newTree) {
        (*newTree).count = 0;
        (*newTree).root = NULL;
        (*newTree).deleteNode = deleteNode;
        (*newTree).insertNode = insertNode;
        (*newTree).inOrder = inOrder;
        (*newTree).preOrder = preOrder;
        (*newTree).postOrder = postOrder;
    }

    return newTree;
}

NODE *searchTreeImplement(NODE *root, int *data) {

}
void debugTreeImplement(TREE *pTree) {

}
bool destroyTreeImplement(TREE *pTree) {

}

TreeModule tree = {
    .createTree = createTreeImplement,
    .searchTree = searchTreeImplement,
    .debugTree = debugTreeImplement,
    .destroyTree = destroyTreeImplement
};