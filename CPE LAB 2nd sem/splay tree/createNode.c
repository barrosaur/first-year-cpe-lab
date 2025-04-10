#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

NODE* createNode(int value) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode) {
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;  
    }
    return newNode;
}