#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Queue structure for breadth-first traversal
typedef struct QueueNode {
    TREENODE *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Queue operations
void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, TREENODE *node) {
    QueueNode *newNode = malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

TREENODE* dequeue(Queue *q) {
    if (isQueueEmpty(q)) return NULL;

    QueueNode *temp = q->front;
    TREENODE *node = temp->treeNode;

    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return node;
}

void freeQueue(Queue *q) {
    while (!isQueueEmpty(q)) {
        dequeue(q);
    }
}

void breadthFirstTraversal(TREENODE *root) {
    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    printf("Breadth-First Traversal: ");
    while (!isQueueEmpty(&q)) {
        TREENODE *current = dequeue(&q);
        printf("%d ", current->value);

        if (current->left) enqueue(&q, current->left);
        if (current->right) enqueue(&q, current->right);
    }
    printf("\n");

    freeQueue(&q);
}