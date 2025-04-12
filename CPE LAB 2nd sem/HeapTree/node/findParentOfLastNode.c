#include <stdio.h>
#include "../tree.h"

NODE *findParentOfLastNode(NODE *root) {
    if(root == NULL) return NULL;

    int nodeCount = countNodes(root);
    if(nodeCount <= 1) return NULL;

    NODE *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int count = 0;
    while(front < rear) {
        NODE *node = queue[front++];
        count++;

        if(node->right && count + 1 == nodeCount) {
            return node;
        }

        if(node->left && !node->right && count == nodeCount - 1) {
            return node;
        }

        if(node->left) queue[rear++] = node->left;
        if(node->right) queue[rear++] = node->right;
    }

    return NULL;
}