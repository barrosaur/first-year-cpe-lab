#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

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

        int temp = node->value;
        node->value = smallest->value;
        smallest->value = temp;

        heapifyDownMin(root, smallest, stepMode);
    }
}