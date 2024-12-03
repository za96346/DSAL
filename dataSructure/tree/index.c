#include "tree.h"
#include <stdio.h>

int main() {
    TREE *newTree = tree.createTree();

    int first = 1;
    int second = 2;
    int third = 3;
    int fourth = 4;
    int fiveth = 5;

    // 新增節點
    (*newTree).root = (*newTree).insertNode((*newTree).root, &third);
    (*newTree).root = (*newTree).insertNode((*newTree).root, &first);
    (*newTree).root = (*newTree).insertNode((*newTree).root, &second);
    (*newTree).root = (*newTree).insertNode((*newTree).root, &fourth);
    (*newTree).root = (*newTree).insertNode((*newTree).root, &fiveth);
    tree.debugTree(newTree);

    // 遍歷
    printf("\npreOrder => ");
    (*newTree).preOrder((*newTree).root);
    printf("\ninorder => ");
    (*newTree).inOrder((*newTree).root);
    printf("\npostOrder => ");
    (*newTree).postOrder((*newTree).root);

    // 刪除節點 @todo 修正 deleteNode bug
    (*newTree).deleteNode((*newTree).root, &first);
    tree.debugTree(newTree);

    return 0;
}