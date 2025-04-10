#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void heapifyDownMin(NODE *root, NODE *node, bool *stepMode) {
    if (node == NULL) return;

    NODE *smallest = node;
    NODE *left = node->left;
    NODE *right = node->right;

    if (left && left->value < smallest->value) {
        smallest = left;
    }

    if (right && right->value < smallest->value) {
        smallest = right;
    }

    if (smallest != node) {
        if (*stepMode) {
            displayTree(root);
            printf("Heapifying %d in Min Heap, press SPACE BAR to continue...\n", node->value);
            waitForSpaceBar("");
        }

        // Swap values
        int temp = node->value;
        node->value = smallest->value;
        smallest->value = temp;

        // Recursively heapify the affected subtree
        heapifyDownMin(root, smallest, stepMode);
    }
}

void heapifyDownMax(NODE *root, NODE *node, bool *stepMode) {
    if (node == NULL) return;

    NODE *largest = node;
    NODE *left = node->left;
    NODE *right = node->right;

    if (left && left->value > largest->value) {
        largest = left;
    }

    if (right && right->value > largest->value) {
        largest = right;
    }

    if (largest != node) {
        if (*stepMode) {
            displayTree(root);
            printf("Heapifying %d in Max Heap, press SPACE BAR to continue...\n", node->value);
            waitForSpaceBar("");
        }

        // Swap values
        int temp = node->value;
        node->value = largest->value;
        largest->value = temp;

        // Recursively heapify the affected subtree
        heapifyDownMax(root, largest, stepMode);
    }
}

NODE *deleteMinHeap(NODE *root, bool *stepMode) {
    if (root == NULL) return NULL;

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    NODE *lastNode = findLastNode(root);
    NODE *parentOfLastNode = findParentOfLastNode(root);

    if (*stepMode) {
        displayTree(root);
        printf("Deleting root %d, replacing with %d, press SPACE BAR to continue...\n",
               root->value, lastNode->value);
        waitForSpaceBar("");
    }

    root->value = lastNode->value;

    if (parentOfLastNode) {
        if (parentOfLastNode->right == lastNode) {
            free(parentOfLastNode->right);
            parentOfLastNode->right = NULL;
        } else {
            free(parentOfLastNode->left);
            parentOfLastNode->left = NULL;
        }
    } else {
        free(root);
        return NULL;
    }
    heapifyDownMin(root, root, stepMode);

    return root;
}

NODE *deleteMaxHeap(NODE *root, bool *stepMode) {
    if (root == NULL) return NULL;

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    NODE *lastNode = findLastNode(root);
    NODE *parentOfLastNode = findParentOfLastNode(root);

    if (*stepMode) {
        displayTree(root);
        printf("Deleting root %d, replacing with %d, press SPACE BAR to continue...\n",
               root->value, lastNode->value);
        waitForSpaceBar("");
    }

    root->value = lastNode->value;

    if (parentOfLastNode) {
        if (parentOfLastNode->right == lastNode) {
            free(parentOfLastNode->right);
            parentOfLastNode->right = NULL;
        } else {
            free(parentOfLastNode->left);
            parentOfLastNode->left = NULL;
        }
    } else {
        free(root);
        return NULL;
    }

    heapifyDownMax(root, root, stepMode);

    return root;
}

void freeTree(NODE *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
