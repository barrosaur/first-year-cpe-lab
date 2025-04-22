#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

QUEUE* createQueue() {
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    if (!queue) return NULL;
    
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(QUEUE* queue) {
    return (queue->front == NULL);
}

void enqueue(QUEUE* queue, NODE* treeNode) {
    QUEUENODE* newNode = (QUEUENODE*)malloc(sizeof(QUEUENODE));
    if (!newNode) return;
    
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
        return;
    }
    
    queue->rear->next = newNode;
    queue->rear = newNode;
}

NODE* dequeue(QUEUE* queue) {
    if (isEmpty(queue)) return NULL;
    
    QUEUENODE* temp = queue->front;
    NODE* treeNode = temp->treeNode;
    
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    return treeNode;
}

void freeQueue(QUEUE* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}