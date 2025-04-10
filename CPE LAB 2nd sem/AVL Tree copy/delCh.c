#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

TREENODE* findMinNode(TREENODE *node) {
    TREENODE *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

TREENODE* deleteNode(TREENODE *root, int value) {
    // Standard BST delete
    if (root == NULL) return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            TREENODE *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TREENODE *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor 
        TREENODE *temp = findMinNode(root->right);

        // Copy the inorder successor's content to this node
        root->value = temp->value;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->value);
    }

    // If the tree had only one node, return
    if (root == NULL) return root;

    // Update height
    root->height = 1 + (getHeight(root->left) > getHeight(root->right) 
                        ? getHeight(root->left) : getHeight(root->right));

    // Get balance factor
    int balance = getBalanceFactor(root);

    // Left Left Case
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void deleteModule(TREENODE **root) {
    int value;
    printf("Enter value to delete: ");
    
    if (scanf("%d", &value) != 1) {
        printf("Invalid input.\n");
        while(getchar() != '\n'); // Clear input buffer
        return;
    }
    while(getchar() != '\n'); // Clear input buffer

    *root = deleteNode(*root, value);
    printf("Value %d deleted (if it existed).\n", value);
    displayTree(*root);
}

void changeModule(TREENODE **root) {
    int oldValue, newValue;
    printf("Enter value to change: ");
    
    if (scanf("%d", &oldValue) != 1) {
        printf("Invalid input.\n");
        while(getchar() != '\n'); // Clear input buffer
        return;
    }
    while(getchar() != '\n'); // Clear input buffer

    printf("Enter new value: ");
    if (scanf("%d", &newValue) != 1) {
        printf("Invalid input.\n");
        while(getchar() != '\n'); // Clear input buffer
        return;
    }
    while(getchar() != '\n'); // Clear input buffer

    // Delete old value
    *root = deleteNode(*root, oldValue);
    
    // Insert new value
    *root = insertNode(*root, newValue);

    printf("Value changed from %d to %d.\n", oldValue, newValue);
    displayTree(*root);
}