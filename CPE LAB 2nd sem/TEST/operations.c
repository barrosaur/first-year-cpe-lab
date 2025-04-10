#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"


NODE *splay(NODE *root, NODE *x, bool *stepMode) {

    if(root == NULL || x == NULL) return root;

    while(x->parent != NULL) {
        NODE *parent = x->parent;
        NODE *grandParent = parent->parent;

        if(*stepMode) {
            displayTree(root);
            waitForSpaceBar("Press SPACE BAR to continue...\n");
        }

        if(grandParent == NULL) {
            // zig or zag
            if(x == parent->left) {
                root = rightRotate(parent); // zig
                if(*stepMode) {
                    displayTree(root);
                    waitForSpaceBar("Press SPACE BAR to continue...\n");
                }
            } else {
                root = leftRotate(parent); // zag
                if(*stepMode) {
                    displayTree(root);
                    waitForSpaceBar("Press SPACE BAR to continue...\n");
                }
            }
        } else {
            // other rotations
            if(parent == grandParent->left) {
                if(x == parent->left) { //zig zig
                    root = rightRotate(grandParent);
                    root = rightRotate(parent);

                    if(*stepMode) {
                        displayTree(root);
                        waitForSpaceBar("Press SPACE BAR to continue...\n");
                    }
                } else {
                    //zig zag
                    parent = leftRotate(parent);
                    root = rightRotate(grandParent);

                    if(*stepMode) {
                        displayTree(root);
                        waitForSpaceBar("Press SPACE BAR to continue...\n");
                    }
                }
            } else {
                if(x == parent->right) {
                    // zag zag
                    root = leftRotate(grandParent);
                    root = leftRotate(parent);

                    if(*stepMode) {
                        displayTree(root);
                        waitForSpaceBar("Press SPACE BAR to continue...\n");
                    }
                } else {
                    // zag zig
                    parent = rightRotate(parent);
                    root = leftRotate(grandParent);

                    if(*stepMode) {
                        displayTree(root);
                        waitForSpaceBar("Press SPACE BAR to continue...\n");
                    }
                }
            }

            NODE *temp = x;
            while(temp->parent != NULL) temp = temp->parent;
            root = temp;
        } 
    }

    return root; //x
}

NODE *insert(NODE *root, int key, bool *stepMode) {

    // if tree empty, new node
    if(root == NULL) {
        NODE *newNode = createNode(key);
        return newNode;
    }

    // find where the node should be inserted
    NODE *current = root;
    NODE *parent = NULL;

    while(current != NULL) {
        parent = current;
        if(key < current->value) {
            current = current->left;
        } else if (key > current->value) {
            current = current->right;
        } else {
            // this is if key exists alr
            return splay(root, current, stepMode);
        }
    }

    // new node just for normal insertion
    NODE *newNode = createNode(key);
    newNode->parent = parent;

    // linking new node to parent
    if(key < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    // splaying newNode to root
    root = splay(root, newNode, stepMode);

    if(*stepMode) {
        displayTree(root);
        waitForSpaceBar("Press SPACE BAR to continue...\n");
    }

    return root;
}

NODE *search(NODE *root, int key, bool *found, bool *stepMode) {
    if(root == NULL) {
        *found = false;
        return NULL;
    }

    // find target node or node closest to target
    NODE *target = findNode(root, key);

    // see if key found
    *found = (target != NULL && target->value == key);

    // splay tree
    root = splay(root, target, stepMode);

    return root;
}

NODE *delete(NODE *root, int key, bool *stepMode) {
    if(root == NULL) return NULL;

    // search and splay node to find target
    bool found = false;
    root = search(root, key, &found, stepMode);

    // if not found, no delete
    if(root->value != key) return root;

    NODE *leftSubtree = root->left;
    NODE *rightSubtree = root->right;

    // clear parent pointers
    if(leftSubtree) leftSubtree->parent = NULL;
    if(rightSubtree) rightSubtree->parent = NULL;
    free(root);

    if(leftSubtree == NULL) return rightSubtree;
    if(rightSubtree == NULL) return leftSubtree;

    // find max node in left subtree
    NODE *maxLeft = leftSubtree;
    while(maxLeft->right != NULL) {
        maxLeft = maxLeft->right;
    } 

    // splay max node
    bool tempStepMode = false;
    leftSubtree = splay(leftSubtree, maxLeft, &tempStepMode);

    // connect
    leftSubtree->right = rightSubtree;
    if(rightSubtree) rightSubtree->parent = leftSubtree;

    if(*stepMode) {
        displayTree(root);
        waitForSpaceBar("Press SPACE BAR to continue...\n");
    }

    return leftSubtree;
}