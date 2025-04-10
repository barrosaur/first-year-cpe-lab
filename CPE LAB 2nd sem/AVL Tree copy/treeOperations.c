#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

TREENODE* createNode(int value) {
    TREENODE* node = (TREENODE*)malloc(sizeof(TREENODE));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int calculateTreeHeight(TREENODE *root) {
    if (root == NULL) return 0;
    
    int leftHeight = calculateTreeHeight(root->left);
    int rightHeight = calculateTreeHeight(root->right);
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int getHeight(TREENODE *node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalanceFactor(TREENODE *node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

TREENODE* rotateRight(TREENODE *y) {
    TREENODE *x = y->left;
    TREENODE *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

TREENODE* rotateLeft(TREENODE *x) {
    TREENODE *y = x->right;
    TREENODE *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

TREENODE* insertNode(TREENODE *node, int value) {
    // Standard BST insertion
    if (node == NULL) return createNode(value);

    if (value < node->value)
        node->left = insertNode(node->left, value);
    else if (value > node->value)
        node->right = insertNode(node->right, value);
    else
        return node; // Duplicate values not allowed

    // Update height
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    // Get balance factor
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && value < node->left->value)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && value > node->right->value)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && value > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void freeTree(TREENODE *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}