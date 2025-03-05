#include <stdio.h>
#include "../tree.h"

TREENODE *insertNode(TREENODE *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    QUEUE *q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        TREENODE *current = dequeue(q);

        if (current->left == NULL) {
            current->left = createNode(value);
            if (current->left == NULL) {
                printf("ERROR: failed to create new node!\n\n");
                freeQueue(q);
                return root;
            }
            freeQueue(q);
            return root;
        }
        else if (current->right == NULL) {
            current->right = createNode(value);
            if (current->right == NULL) {
                printf("ERROR: failed to create new node!\n\n");
                freeQueue(q);
                return root;
            }
            freeQueue(q);
            return root;
        }
        else {
            enqueue(q, current->left);
            enqueue(q, current->right);
        }
    }

    freeQueue(q);
    return root;
}
