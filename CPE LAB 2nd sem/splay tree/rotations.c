#include <stdio.h>
#include "tree.h"

NODE* rightRotate(NODE* y) {
    NODE* x = y->left;
    NODE* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update parent pointers
    x->parent = y->parent;
    y->parent = x;
    if (T2) T2->parent = y;

    // Update parent's child pointer if y wasn't root
    if (x->parent) {
        if (x->parent->left == y)
            x->parent->left = x;
        else
            x->parent->right = x;
    }

    return x;
}

NODE* leftRotate(NODE* x) {
    NODE* y = x->right;
    NODE* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update parent pointers
    y->parent = x->parent;
    x->parent = y;
    if (T2) T2->parent = x;

    // Update parent's child pointer if x wasn't root
    if (y->parent) {
        if (y->parent->left == x)
            y->parent->left = y;
        else
            y->parent->right = y;
    }

    return y;
}