#ifndef TREE_H
#define __TREE_H

#include <stdbool.h>

#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 40

// Tree Node Structure
typedef struct TREENODE {
    int value;
    int height;
    struct TREENODE *left;
    struct TREENODE *right;
} TREENODE;

// Input structure from inputModule
typedef struct {
    int *arr;
    int size;
} Input;

// Color function prototypes
void red();
void reset();

// Input Module Function
Input inputModule();

// Tree Operations Prototypes
TREENODE* createNode(int value);
int getHeight(TREENODE *node);
int getBalanceFactor(TREENODE *node);
TREENODE* rotateRight(TREENODE *y);
TREENODE* rotateLeft(TREENODE *x);
TREENODE* insertNode(TREENODE *node, int value);
TREENODE* deleteNode(TREENODE *root, int value);
void freeTree(TREENODE *root);

// Tree Display Prototypes
int calculateTreeHeight(TREENODE *root);
void displayTree(TREENODE *root);
void printBuffers(char *buffer[], int height);
void printTree(TREENODE *root, char *buffer[], int height, int level, int col, int row);

// Traversal Prototypes
void breadthFirstTraversal(TREENODE *root);

// Menu and Module Prototypes
void mainMenu(TREENODE **root);
void appendModule(TREENODE **root);
void browseModule(TREENODE *root);
void changeModule(TREENODE **root);
void deleteModule(TREENODE **root);

#endif // TREE_H