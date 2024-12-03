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
    NODE *minNode;
    while ((*pNode).left != NULL)
    {
        if ((*pNode).data < (*minNode).data) {
            minNode = pNode;
        }

        pNode = (*pNode).left;
    }
    return minNode;
}
NODE *deleteNode(NODE*pNode, int *data) {
    if (pNode == NULL) return NULL;

    // 遞迴刪除
    if (*(*pNode).data > *data) {
        (*pNode).left = deleteNode((*pNode).left, data);
    } else if (*(*pNode).data < *data) {
        (*pNode).right = deleteNode((*pNode).right, data);
    } else {
        /**
         * @details 三種情況
         * 1. 沒有子樹 -> 直接釋放 該節點
         * 2. 只有左子樹或是右子樹 -> 刪除原本節點，該子樹遞補
         * 3. 有兩個子樹的話 -> 找到右子樹的最小植或是左子樹的最大值做遞補
        */
        if ((*pNode).left == NULL && (*pNode).right == NULL) {
            free(pNode);
            return NULL;
        } else if ((*pNode).left == NULL) {
            NODE *temp = (*pNode).right;
            free(temp);
            return (*pNode).right;
        } else if ((*pNode).right == NULL) {
            NODE *temp = (*pNode).left;
            free(temp);
            return (*pNode).left;
        } else {
            NODE *leftMaxNode = findLeftMax((*pNode).left);

            (*pNode).data = (*leftMaxNode).data;
            (*pNode).left = deleteNode((*pNode).left, (*leftMaxNode).data);
        }
    }
    return pNode;
}

// 前序遍歷 root -> left -> right
void preOrder(NODE *pNode){
    if (pNode != NULL) {
        printf("%d", *(*pNode).data);
        preOrder((*pNode).left);
        preOrder((*pNode).right);
    }
}

// 中序遍歷 left -> root -> right
void inOrder(NODE *pNode){
    if (pNode != NULL) {
        inOrder((*pNode).left);
        printf("%d", *(*pNode).data);
        inOrder((*pNode).right);
    }
}

// 後續遍歷 left -> right -> root
void postOrder(NODE *pNode){
    if (pNode != NULL) {
        postOrder((*pNode).left);
        postOrder((*pNode).right);
        printf("%d", *(*pNode).data);
    }
}

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

// 递归打印树的每个节点，缩进表示层级
void printTreeRecursive(NODE *pNode, int level) {
    if (pNode == NULL) {
        return;
    }

    // 打印当前节点的数据，使用缩进表示层级
    for (int i = 0; i < level; i++) {
        printf("  "); // 打印缩进
    }
    printf("Node data: %d\n", *(pNode->data));

    // 递归打印左子树
    printTreeRecursive(pNode->left, level + 1);
    
    // 递归打印右子树
    printTreeRecursive(pNode->right, level + 1);
}

void debugTreeImplement(TREE *pTree) {
    printf("\nTree structure:\n");
    printf("---------------------------\n");
    if (pTree == NULL || pTree->root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    printTreeRecursive(pTree->root, 0);
    printf("---------------------------\n");
}

bool destroyTreeImplement(TREE *pTree) {
    if (pTree == NULL || pTree->root == NULL) {
        printf("Tree is empty.\n");
        return false;
    }

    printf("Tree structure:\n");
    printTreeRecursive(pTree->root, 0);
    return true;
}

TreeModule tree = {
    .createTree = createTreeImplement,
    .debugTree = debugTreeImplement,
    .destroyTree = destroyTreeImplement
};