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

NODE* splay(NODE* root, NODE* x) {
    if (root == NULL || x == NULL) return root;

    while (x->parent != NULL) {
        NODE* parent = x->parent;
        NODE* grandparent = parent->parent;

        if (grandparent == NULL) {
            if (x == parent->left) {
                root = rightRotate(parent); 
            } else {
                root = leftRotate(parent);  
            }
        } else {
            if (parent == grandparent->left) {
                if (x == parent->left) {
                    root = rightRotate(grandparent);
                    root = rightRotate(parent);
                } else {
                    parent = leftRotate(parent);
                    root = rightRotate(grandparent);
                }
            } else {
                if (x == parent->right) {
                    root = leftRotate(grandparent);
                    root = leftRotate(parent);
                } else {
                    parent = rightRotate(parent);
                    root = leftRotate(grandparent);
                }
            }
            
            NODE* temp = x;
            while (temp->parent != NULL) {
                temp = temp->parent;
            }
            root = temp;
        }
    }

    return root;
}

NODE* insert(NODE* root, int key) {
    if (root == NULL) {
        NODE* newNode = createNode(key);
        return newNode;
    }
    
    NODE* current = root;
    NODE* parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (key < current->value)
            current = current->left;
        else if (key > current->value)
            current = current->right;
        else {
            return splay(root, current);
        }
    }
    
    NODE* newNode = createNode(key);
    newNode->parent = parent;
    
    if (key < parent->value) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    root = splay(root, newNode);
    
    return root;
}