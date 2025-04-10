#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

void displayTree(TREENODE *root) {
    if(root == NULL) {
        printf("Tree empty!\n\n");
        return;
    }

    int height = calculateTreeHeight(root);
    int bufferHeight = height * 2 - 1; //branch lines;

    if(bufferHeight > CONSOLE_HEIGHT - 5) {
        bufferHeight = CONSOLE_HEIGHT - 5; //room for menu and the prompts
    }
    
    // ensure at least one line for display
    if (bufferHeight < 1) {
        bufferHeight = 1;
    }

    char *buffer[bufferHeight];
    for(int i = 0; i < bufferHeight; i++) {
        buffer[i] = (char*)malloc(sizeof(char) * (CONSOLE_WIDTH + 1));
        if (buffer[i] == NULL) {
            printf("ERROR: Memory allocation failed for display buffer!\n\n");
            
            // Free previously allocated buffers
            for (int j = 0; j < i; j++) {
                free(buffer[j]);
            }
            return;
        }
        
        memset(buffer[i], ' ', CONSOLE_WIDTH);
        buffer[i][CONSOLE_WIDTH] = '\0';
    }

    //tree to buffer
    printTree(root, buffer, height, 0, CONSOLE_WIDTH / 2, CONSOLE_WIDTH / 2);

    //buffer to console
    printBuffers(buffer, bufferHeight);

    //free
    for(int i = 0; i < bufferHeight; i++) {
        free(buffer[i]);
    }

    return;
}

void printBuffers(char *buffer[], int height) {
    for(int i = 0; i < height; i++) {
        printf("%s\n", buffer[i]);
    }
}

void printTree(TREENODE *root, char *buffer[], int height, int level, int col, int row) {
    if(root == NULL) {
        return;
    }

    // no buffer overflow
    if (level >= height * 2 - 1) {
        return;
    }

    char valueStr[20]; // size++ safety
    sprintf(valueStr, "%d", root->value);
    int valueLen = strlen(valueStr);

    //position calculation
    int position = col - valueLen / 2;

    if(position < 0) {
        position = 0;
    }
    if(position >= CONSOLE_WIDTH - valueLen) {
        position = CONSOLE_WIDTH - valueLen - 1;
    }

    //place value at calc pos
    for(int i = 0; i < valueLen && position + i < CONSOLE_WIDTH; i++) {
        buffer[level][position + i] = valueStr[i];
    }

    //branches for children
    int nextLvl = level + 2;
    
    // if exceed height not allowed
    if (nextLvl >= height * 2 - 1) {
        return;
    }
    
    int nextWidth = row / 2;
    if (nextWidth < 1) nextWidth = 1;

    if(root->left != NULL) {
        int leftCol = col - nextWidth;
        if (leftCol < 0) leftCol = 0;

        //left branch
        int branchPos = col - 1;
        if(branchPos > 0 && branchPos < CONSOLE_WIDTH) {
            buffer[level + 1][branchPos] = 'v';
        }

        for(int i = leftCol + 1; i < branchPos && i < CONSOLE_WIDTH; i++) {
            if(i >= 0) {
                buffer[level+1][i] = '-';
            }
        }

        printTree(root->left, buffer, height, nextLvl, leftCol, nextWidth);
    }

    if(root->right != NULL) {
        int rightCol = col + nextWidth;
        if (rightCol >= CONSOLE_WIDTH) rightCol = CONSOLE_WIDTH - 1;

        //right branch
        int branchPos = col + valueLen;
        if(branchPos < CONSOLE_WIDTH) {
            buffer[level + 1][branchPos] = 'v';
        }

        for(int i = branchPos + 1; i < rightCol && i < CONSOLE_WIDTH; i++) {
            if(i >= 0) {
                buffer[level+1][i] = '-';
            }
        }

        printTree(root->right, buffer, height, nextLvl, rightCol, nextWidth);
    }

    // for '+'
    if(root->left != NULL && root->right != NULL) {
        int leftPos = col - 1;
        int rightPos = col + valueLen;

        if(leftPos >= 0 && leftPos < CONSOLE_WIDTH && rightPos >= 0 && rightPos < CONSOLE_WIDTH) {
            bool leftLine = false, rightLine = false;

            for(int i = 0; i < leftPos; i++) {
                if(buffer[level+1][i] == '-') {
                    leftLine = true;
                    break;
                }
            }

            for(int i = rightPos + 1; i < CONSOLE_WIDTH; i++) {
                if(buffer[level + 1][i] == '-') {
                    rightLine = true;
                    break;
                }
            }

            if(leftLine && rightLine) {
                int plusPos = (leftPos + rightPos) / 2;
                if(plusPos > leftPos && plusPos < rightPos && plusPos < CONSOLE_WIDTH) {
                    buffer[level+1][plusPos] = '+';
                }
            }
        }
    }

    return;
}