#ifndef TREE_H
#define TREE_H

#define CONSOLE_WIDTH 80
#define CONSOLE_HEIGHT 25

#include <stdbool.h>

typedef struct node {
    int value;
    struct node *left, *right, *parent;
} NODE;

typedef struct {
    int *arr;
    int size;
} INPUT;

// other
void displayMenu();
void clearInputBuffer();
void waitForSpaceBar(const char *msg);
void freeTree(NODE *root);

// input
INPUT inputModule();
void inputHandle(int arr[], int arrSize, NODE **root);

// splay operations
NODE *splay(NODE *root, NODE *x, bool *stepMode);

// node
NODE *createNode(int value);
NODE *findNode(NODE *root, int key);

// display
void printTree(NODE *root, char *buffer[], int height, int level, int col, int width);
void printBuffers(char *buffer[], int height);
void displayTree(NODE *root);
int calculateTreeHeight(NODE *root);

// rotations
NODE *rightRotate(NODE *y);
NODE *leftRotate(NODE *x);
NODE *insert(NODE *root, int key, bool *stepMode);
NODE *search(NODE *root, int key, bool *found, bool *stepMode);
NODE *delete(NODE *root, int key, bool *stepMode);

// module functions
void addNodeModule(NODE **root);
void deleteNodeModule(NODE **root);
void searchNodeModule(NODE **root);

#endif