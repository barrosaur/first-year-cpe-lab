#include <stdio.h>
#include "../tree.h"

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

        int temp = node->value;
        node->value = largest->value;
        largest->value = temp;

        heapifyDownMax(root, largest, stepMode);
    }
}