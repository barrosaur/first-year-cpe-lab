#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

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

//utility.c
INPUT inputModule();
void printTree(NODE *root, char *buffer[], int height, int level, int col, int width);
void printBuffers(char *buffer[], int height);
void displayTree(NODE *root);
int calculateTreeHeight(NODE *root);
void waitForSpaceBar(const char *msg);
void clearInputBuffer();
void inputHandle(int arr[], int arrSize, NODE **minRoot, NODE **maxRoot);
void displayBothHeaps(NODE *minRoot, NODE *maxRoot);

//module.c
void appendNodeModule(NODE **minRoot, NODE **maxRoot);
void deleteNodeModule(NODE **minRoot, NODE **maxRoot);

//nodeFunctions.c
NODE *createNode(int value);
NODE *findParent(NODE *root, int height, int nodeCount);
int countNodes(NODE *root);
NODE *insertMinHeap(NODE *root, int value, bool *stepMode);
NODE *insertMaxHeap(NODE *root, int value, bool *stepMode);
NODE *findLastNode(NODE *root);
NODE *findParentOfLastNode(NODE *root);

//heapify.c
void heapifyDownMin(NODE *root, NODE *node, bool *stepMode);
void heapifyDownMax(NODE *root, NODE *node, bool *stepMode);
NODE *deleteMinHeap(NODE *root, bool *stepMode);
NODE *deleteMaxHeap(NODE *root, bool *stepMode);
void freeTree(NODE *root);

#endif // TREE_H_INCLUDED
