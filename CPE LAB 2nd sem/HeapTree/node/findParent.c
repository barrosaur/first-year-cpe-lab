#include <stdio.h>
#include "../tree.h"

NODE *findParent(NODE *root, int height, int nodeCount) {
    if(root == NULL || height <= 1) return root;

    int parentIndex = (nodeCount - 1) / 2;
    int currentIndex = 1;
    NODE *current = root;

    NODE *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while(front < rear) {
        NODE *node = queue[front++];
        currentIndex++;

        if(currentIndex > parentIndex) {
            return node;
        }

        if(node->left) queue[rear++] = node->left;
        if(node->right) queue[rear++] = node->right;
    }

    return root;
}