#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

NODE* splay(NODE* root, NODE* x, bool* stepMode) {
    if (root == NULL || x == NULL) return root;

    while (x->parent != NULL) {
        NODE* parent = x->parent;
        NODE* grandparent = parent->parent;

        if (*stepMode) {
            printf("Splaying for node %d, current root is %d\n", x->value, root->value);
            displayTree(root);
            waitForSpaceBar("Press SPACE BAR to continue splaying...");
        }

        if (grandparent == NULL) {
            // Case 1: Parent is root (Zig/Zag)
            if (x == parent->left) {
                root = rightRotate(parent); // Zig (right rotate parent)
                if (*stepMode) {
                    printf("Performed Zig (right rotation)\n");
                    displayTree(root);
                    waitForSpaceBar("Press SPACE BAR to continue splaying...");
                }
            } else {
                root = leftRotate(parent);  // Zag (left rotate parent)
                if (*stepMode) {
                    printf("Performed Zag (left rotation)\n");
                    displayTree(root);
                    waitForSpaceBar("Press SPACE BAR to continue splaying...");
                }
            }
        } else {
            // Determine rotation type
            if (parent == grandparent->left) {
                if (x == parent->left) {
                    // Zig-Zig (right-right)
                    root = rightRotate(grandparent);
                    root = rightRotate(parent);
                    if (*stepMode) {
                        printf("Performed Zig-Zig (right-right rotations)\n");
                        displayTree(root);
                        waitForSpaceBar("Press SPACE BAR to continue splaying...");
                    }
                } else {
                    // Zig-Zag (right-left)
                    parent = leftRotate(parent);
                    root = rightRotate(grandparent);
                    if (*stepMode) {
                        printf("Performed Zig-Zag (right-left rotations)\n");
                        displayTree(root);
                        waitForSpaceBar("Press SPACE BAR to continue splaying...");
                    }
                }
            } else {
                if (x == parent->right) {
                    // Zag-Zag (left-left)
                    root = leftRotate(grandparent);
                    root = leftRotate(parent);
                    if (*stepMode) {
                        printf("Performed Zag-Zag (left-left rotations)\n");
                        displayTree(root);
                        waitForSpaceBar("Press SPACE BAR to continue splaying...");
                    }
                } else {
                    // Zag-Zig (left-right)
                    parent = rightRotate(parent);
                    root = leftRotate(grandparent);
                    if (*stepMode) {
                        printf("Performed Zag-Zig (left-right rotations)\n");
                        displayTree(root);
                        waitForSpaceBar("Press SPACE BAR to continue splaying...");
                    }
                }
            }
            
            // Find the new root after rotations
            NODE* temp = x;
            while (temp->parent != NULL) {
                temp = temp->parent;
            }
            root = temp;
        }
    }

    return root; // x is now the root
}

// Correctly implemented insert function
NODE* insert(NODE* root, int key, bool* stepMode) {
    // If tree is empty, create a new node
    if (root == NULL) {
        NODE* newNode = createNode(key);
        return newNode;
    }
    
    // Find where to insert the new node
    NODE* current = root;
    NODE* parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (key < current->value)
            current = current->left;
        else if (key > current->value)
            current = current->right;
        else {
            // Key already exists, splay and return
            return splay(root, current, stepMode);
        }
    }
    
    // Create new node
    NODE* newNode = createNode(key);
    newNode->parent = parent;
    
    // Link new node to parent
    if (key < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;
    
    // Splay the new node to root
    root = splay(root, newNode, stepMode);
    
    if (*stepMode) {
        printf("After insertion of %d:\n", key);
        displayTree(root);
        waitForSpaceBar("Press SPACE BAR to continue...");
    }
    
    return root;
}

// Corrected search function
NODE* search(NODE* root, int key, bool* found, bool* stepMode) {
    if (root == NULL) {
        *found = false;
        return NULL;
    }
    
    // Find the target node or closest node
    NODE* target = findNode(root, key);
    
    // Check if key was found
    *found = (target != NULL && target->value == key);
    
    // Splay the tree
    root = splay(root, target, stepMode);
    
    return root;
}

// Helper function to find maximum value node
NODE* findMax(NODE* root) {
    if (root == NULL) return NULL;
    
    // Traverse to the rightmost node
    NODE* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    
    return current;
}

// Corrected delete function
NODE* delete(NODE* root, int key, bool* stepMode) {
    if (root == NULL) return NULL;
    
    // Search and splay the node to delete (or closest node)
    bool found = false;
    root = search(root, key, &found, stepMode);
    
    // If key not found, nothing to delete
    if (root->value != key) return root;
    
    // Store left and right subtrees
    NODE* leftSubtree = root->left;
    NODE* rightSubtree = root->right;
    
    // Clear parent pointers
    if (leftSubtree) leftSubtree->parent = NULL;
    if (rightSubtree) rightSubtree->parent = NULL;
    
    // Free the node to delete
    free(root);
    
    // If left subtree is empty, return right subtree
    if (leftSubtree == NULL) {
        return rightSubtree;
    }
    
    // If right subtree is empty, return left subtree
    if (rightSubtree == NULL) {
        return leftSubtree;
    }
    
    // Find maximum in left subtree
    NODE* maxLeft = leftSubtree;
    while (maxLeft->right != NULL) {
        maxLeft = maxLeft->right;
    }
    
    // Splay max node to the root of left subtree
    bool tempStepMode = false; // Turn off step mode temporarily
    leftSubtree = splay(leftSubtree, maxLeft, &tempStepMode);
    
    // Connect right subtree to left subtree
    leftSubtree->right = rightSubtree;
    if (rightSubtree) rightSubtree->parent = leftSubtree;
    
    if (*stepMode) {
        printf("After deletion of %d:\n", key);
        displayTree(leftSubtree);
        waitForSpaceBar("Press SPACE BAR to continue...");
    }
    
    return leftSubtree;
}


// Free the entire tree
void freeTree(NODE* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

NODE* findNode(NODE* root, int key) {
    NODE* current = root;
    NODE* last = NULL;

    while (current != NULL) {
        last = current;
        if (key < current->value)
            current = current->left;
        else if (key > current->value)
            current = current->right;
        else
            return current; // Found exact match
    }
    
    return last; // Return the last visited node if no exact match
}