#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

// TREENODE *deleteNode(TREENODE *root, int value) {
//     if(root == NULL) {
//         return root;
//     }

//     // If the node to be deleted is found
//     if(root->value == value) {
//         // Node with only one child or no child
//         if(root->left == NULL) {
//             TREENODE *temp = root->right;
//             free(root);
//             return temp;
//         } else if(root->right == NULL) {
//             TREENODE *temp = root->left;
//             free(root);
//             return temp;
//         }

//         // Node with two children: Get the inorder successor (smallest in the right subtree)
//         TREENODE *temp = findMin(root->right);

//         // Copy the inorder successor's content to this node
//         root->value = temp->value;

//         // Delete the inorder successor
//         root->right = deleteNode(root->right, temp->value);
//     } else {
//         // Recursively delete in the left and right subtrees
//         root->left = deleteNode(root->left, value);
//         root->right = deleteNode(root->right, value);
//     }

//     return root;
// }

TREENODE *deleteNode(TREENODE *root, int value) {
    if (root == NULL) {
        return root;
    }

    // If the node to be deleted is found
    if (root->value == value) {
        // Case 1: Node is a leaf node
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node has one child
        if (root->left == NULL) {
            TREENODE *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            TREENODE *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        // Find the lowest level and rightmost node
        TREENODE *parent = NULL;
        TREENODE *current = root->left; // Start from the left subtree

        // Traverse to the lowest level and rightmost node
        while (current->right != NULL) {
            parent = current;
            current = current->right;
        }

        // Replace the value of the node to delete with the rightmost node's value
        root->value = current->value;

        // Delete the rightmost node
        if (parent == NULL) {
            // If the rightmost node is the left child of the root
            root->left = current->left;
        } else {
            // If the rightmost node is deeper in the tree
            parent->right = current->left;
        }

        free(current);
        return root;
    }

    // Recursively delete in the left and right subtrees
    root->left = deleteNode(root->left, value);
    root->right = deleteNode(root->right, value);

    return root;
}