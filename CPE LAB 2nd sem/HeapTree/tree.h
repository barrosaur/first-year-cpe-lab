#ifndef TREE_H
#define TREE_H

#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 25

#include <stdbool.h>

typedef struct {
    int *arr;
    int size;
} INPUT;

typedef struct node {
    int value;
    struct node *left, *right;
} NODE;

typedef enum {
    MIN_HEAP,
    MAX_HEAP
} HEAP_TYPE;

// input
INPUT inputModule();
void waitForSpaceBar(const char *msg);
void clearInputBuffer();
void inputHandle(int arr[], int arrSize, NODE **minRoot, NODE **maxRoot);

// display
void printTree(NODE *root, char *buffer[], int height, int level, int col, int width);
void printBuffers(char *buffer[], int height);
void displayTree(NODE *root);
int calculateTreeHeight(NODE *root);
void displayBothHeaps(NODE *minRoot, NODE *maxRoot);

// node functions
NODE *createNode(int value);
NODE *findParent(NODE *root, int height, int nodeCount);
int countNodes(NODE *root);
NODE *findLastNode(NODE *root);
NODE *findParentOfLastNode(NODE *root);

// heap functions
NODE *insertMinHeap(NODE *root, int value, bool *stepMode);
NODE *insertMaxHeap(NODE *root, int value, bool *stepMode);
void heapifyDownMin(NODE *root, NODE *node, bool *stepMode);
void heapifyDownMax(NODE *root, NODE *node, bool *stepMode);
NODE *deleteMinHeap(NODE *root, bool *stepMode);
NODE *deleteMaxHeap(NODE *root, bool *stepMode);
void freeTree(NODE *root);

// module
void appendNodeModule(NODE **minRoot, NODE **maxRoot);
void deleteNodeModule(NODE **minRoot, NODE **maxRoot);

#endif