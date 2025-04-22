#ifndef TREE_H
#define TREE_H

typedef struct {
    int *arr;
    int size;
} INPUT;

typedef struct node {
    int value;
    struct node *prev;  
    struct node *next;  
    struct node *parent;
} NODE;

typedef struct QueueNode {
    NODE* treeNode;
    struct QueueNode* next;
} QUEUENODE;

typedef struct {
    QUEUENODE* front;
    QUEUENODE* rear;
} QUEUE;

// input
INPUT inputModule();

//nodeFunctions
NODE *createNode(int value);
NODE *splay(NODE *root, NODE *x);
NODE *insert(NODE *root, int key);

// rotations
NODE* rightRotate(NODE* y);
NODE* leftRotate(NODE* x);
void breadthFirstTraversal(NODE* root);

// calculations
int calculateTreeHeight(NODE *root);
int calculateLeftSubtreeHeight(NODE *root);
int calculateRightSubtreeHeight(NODE *root);
void freeTree(NODE* node);

// queue
QUEUE* createQueue();
int isEmpty(QUEUE* queue);
void enqueue(QUEUE* queue, NODE* treeNode);
NODE* dequeue(QUEUE* queue);
void freeQueue(QUEUE* queue);

#endif