#include <stdio.h>
#include "tree.h"

/*
 
        y
      /  \
     x
      \
       a 

*/

NODE *rightRotate(NODE *y) {
    NODE *x = y->left;
    NODE *a = x->right;
    

    // rotation
    x->right = y;
    y->left = a;

    // update parents
    x->parent = y->parent;
    y->parent = x;
    if(a) a->parent = y;

    // update parent child
    if(x->parent) {
        if(x->parent->left == y) {
            x->parent->left = x;
        } else {
            x->parent->right = x;
        }
    }

    return x;
}

/* 
        x
      /  \
         y
        /
        a
*/

NODE *leftRotate(NODE *x) {
    NODE *y = x->right;
    NODE *a = y->left;

    // rotation
    y->left = x;
    x->right = a;

    // update parent pointers
    y->parent = x->parent;
    x->parent = y;
    if(a) a->parent = x;

    // update parent children
    if(y->parent) {
        if(y->parent->left == x) {
            y->parent->left = y;
        } else {
            y->parent->right = y;
        }
    }

    return y;
}