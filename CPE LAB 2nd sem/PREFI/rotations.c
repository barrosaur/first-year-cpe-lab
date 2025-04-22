#include <stdio.h>
#include "tree.h"

NODE* rightRotate(NODE* y) {
    NODE* x = y->left;
    NODE* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->parent = y->parent;
    y->parent = x;
    if (T2) T2->parent = y;

    if (x->parent) {
        if (x->parent->left == y)
            x->parent->left = x;
        else
            x->parent->right = x;
    }

    return x;
}

NODE* leftRotate(NODE* x) {
    NODE* y = x->right;
    NODE* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->parent = x->parent;
    x->parent = y;
    if (T2) T2->parent = x;

    if (y->parent) {
        if (y->parent->left == x)
            y->parent->left = y;
        else
            y->parent->right = y;
    }

    return y;
}

void breadthFirstTraversal(NODE* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    
    QUEUE* queue = createQueue();
    if (!queue) {
        printf("Queue creation failed\n");
        return;
    }
    
    printf("Breadth-First Traversal: ");
    
    enqueue(queue, root);
    
    while (!isEmpty(queue)) {
        NODE* current = dequeue(queue);
        printf("%d ", current->value);
        
        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }
    
    printf("\n");
    freeQueue(queue);
}