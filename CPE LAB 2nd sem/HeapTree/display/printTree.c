#include <stdio.h>
#include <string.h>
#include "../tree.h"

void printTree(NODE *root, char *buffer[], int height, int level, int col, int width) {
    if(root == NULL) {
        return;
    }

    // Avoid buffer overflow
    if (level >= height * 2 - 1) {
        return;
    }

    // Convert value to string
    char valueStr[20];
    sprintf(valueStr, "%d", root->value);
    int valueLen = strlen(valueStr);

    // Calculate position for center alignment
    int position = col - valueLen / 2;

    // Boundary checks
    if(position < 0) {
        position = 0;
    }
    if(position >= CONSOLE_WIDTH - valueLen) {
        position = CONSOLE_WIDTH - valueLen - 1;
    }

    // Place value at calculated position
    for(int i = 0; i < valueLen && position + i < CONSOLE_WIDTH; i++) {
        buffer[level][position + i] = valueStr[i];
    }

    // Calculate next level and horizontal spacing
    int nextLvl = level + 2;
    int leftWidth = width / 2;
    int rightWidth = width / 2;

    // If width becomes too small, use minimum width
    if (leftWidth < 1) leftWidth = 1;
    if (rightWidth < 1) rightWidth = 1;

    // Don't render if we exceed buffer height
    if (nextLvl >= height * 2 - 1) {
        return;
    }

    // Left child
    if(root->left != NULL) {
        // Calculate left child column position with balanced spacing
        int leftCol = col - leftWidth;
        if (leftCol < 0) leftCol = 0;

        // Draw left branch character
        int branchPos = col - 1;
        if(branchPos > 0 && branchPos < CONSOLE_WIDTH) {
            buffer[level + 1][branchPos] = '/';
        }

        // Draw connecting line
        for(int i = leftCol + valueLen/2; i < branchPos && i < CONSOLE_WIDTH; i++) {
            if(i >= 0) {
                buffer[level+1][i] = '-';
            }
        }

        // Recursively print left subtree
        printTree(root->left, buffer, height, nextLvl, leftCol, leftWidth);
    }

    // Right child
    if(root->right != NULL) {
        // Calculate right child column position with balanced spacing
        int rightCol = col + rightWidth;
        if (rightCol >= CONSOLE_WIDTH) rightCol = CONSOLE_WIDTH - 1;

        // Draw right branch character
        int branchPos = col + valueLen;
        if(branchPos < CONSOLE_WIDTH) {
            buffer[level + 1][branchPos] = '\\';
        }

        // Draw connecting line
        for(int i = branchPos + 1; i < rightCol && i < CONSOLE_WIDTH; i++) {
            if(i >= 0) {
                buffer[level+1][i] = '-';
            }
        }

        // Recursively print right subtree
        printTree(root->right, buffer, height, nextLvl, rightCol, rightWidth);
    }
}