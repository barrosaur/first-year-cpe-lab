#include <stdio.h>
#include "../tree.h"

NODE *createNode(int value) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if(newNode == NULL) return NULL;

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}