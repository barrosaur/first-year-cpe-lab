#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 25

typedef struct node {
    int value;
    struct node *left, *right;
    struct node *parent;  // Added parent pointer
} NODE;

typedef struct {
    int *arr;
    int size;
} INPUT;

// display
void printTree(NODE *root, char *buffer[], int height, int level, int col, int row);
void printBuffers(char *buffer[], int height);
void displayTree(NODE *root);
int calculateTreeHeight(NODE *root);

INPUT inputModule();

// node operations
NODE *createNode(int value);

// rotations
NODE *rightRotate(NODE *x);
NODE *leftRotate(NODE *x);

// splay operations
NODE *splay(NODE *root, NODE *x, bool *stepMode);
NODE *findNode(NODE *root, int key);
NODE *insert(NODE *root, int key, bool *stepMode);
NODE *search(NODE *root, int key, bool *found, bool *stepMode);
NODE *delete(NODE *root, int key, bool *stepMode);

void freeTree(NODE *root);
void waitForSpaceBar(const char* message);

#endif