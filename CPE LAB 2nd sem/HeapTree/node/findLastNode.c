#include <stdio.h>
#include "../tree.h"

NODE *findLastNode(NODE *root) {
    if(root == NULL) return NULL;

    int nodeCount = countNodes(root);

    NODE *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int count = 0;
    while(front < rear) {
        NODE *node = queue[rear++];
        count++;

        if(count == nodeCount) {
            return node;
        }

        if(node->left) queue[rear++] = node->left;
        if(node->right) queue[rear++] = node->right;
    }

    return NULL;
}