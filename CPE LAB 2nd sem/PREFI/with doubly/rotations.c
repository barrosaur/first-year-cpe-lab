#include <stdio.h>
#include "tree.h"

NODE* rightRotate(NODE* y) {
    NODE* x = y->prev;     
    NODE* T2 = x->next;    

    x->next = y;           
    y->prev = T2;          

    x->parent = y->parent;
    y->parent = x;
    if (T2) T2->parent = y;

    if (x->parent) {
        if (x->parent->prev == y)  
            x->parent->prev = x;   
        else
            x->parent->next = x;   
    }

    return x;
}

NODE* leftRotate(NODE* x) {
    NODE* y = x->next;     
    NODE* T2 = y->prev;    

    y->prev = x;           
    x->next = T2;          

    y->parent = x->parent;
    x->parent = y;
    if (T2) T2->parent = x;

    if (y->parent) {
        if (y->parent->prev == x)  
            y->parent->prev = y;   
        else
            y->parent->next = y;   
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
        
        if (current->prev != NULL) {  
            enqueue(queue, current->prev);
        }
        
        if (current->next != NULL) {  
            enqueue(queue, current->next);
        }
    }
    
    printf("\n");
    freeQueue(queue);
}