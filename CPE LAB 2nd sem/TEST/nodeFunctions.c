#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

NODE *createNode(int value) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if(newNode == NULL) return NULL;

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

NODE *findNode(NODE *root, int key) {
    NODE *current = root;
    NODE *last = NULL;

    while(current != NULL) {
        last = current;

        if(key < current->value) {
            current = current->left;
        } else if (key > current->value) {
            current = current->right;
        } else {
            return current; // found the exact match
        }
    }

    return last;
}