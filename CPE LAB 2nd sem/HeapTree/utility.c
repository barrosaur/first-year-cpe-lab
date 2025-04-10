#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

INPUT inputModule() {
    char inpArr[100];
    int *nums = NULL, numIndex = 0;
    INPUT input;

    printf("Enter array of numbers:\n");
    while(1) {
        fgets(inpArr, sizeof(inpArr), stdin);
        inpArr[strcspn(inpArr, "\n")] = '\0';

        // loops through the string and converts the nonspace as integers
        for(int i = 0; inpArr[i] != '\0'; i++) {
            if(isdigit(inpArr[i])) {
                int num = 0;

                // handles multi-digit numbers
                while (isdigit(inpArr[i])) {
                    num = num * 10 + (inpArr[i] - '0'); // conversion
                    i++;
                }
                i--; // after the multi-digit, it will go back to original count

                int *temp = realloc(nums, (numIndex + 1) * sizeof(int));

                // if malloc fails
                if(!temp) {
                    printf("ERROR: memory reallocation failed!\n\n");
                    input.arr = NULL;
                    input.size = 0;
                    free(temp);
                    return input;
                }

                nums = temp;
                nums[numIndex++] = num;
            }
        }

        if(strchr(inpArr, '!')) {
            break;
        }
    }

    input.arr = nums;
    input.size = numIndex;

    return input;
}

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

void printBuffers(char *buffer[], int height) {
    for(int i = 0; i < height; i++) {
        printf("%s\n", buffer[i]);
    }
}

void displayTree(NODE *root) {
    if(root == NULL) {
        printf("Tree empty!\n\n");
        return;
    }

    // Calculate tree height
    int height = calculateTreeHeight(root);
    int bufferHeight = height * 2 - 1; // Include space for branch lines

    // Ensure buffer height fits console
    if(bufferHeight > CONSOLE_HEIGHT - 5) {
        bufferHeight = CONSOLE_HEIGHT - 5; // Leave room for menu and prompts
    }

    // Ensure at least one line for display
    if (bufferHeight < 1) {
        bufferHeight = 1;
    }

    // Create and initialize buffer
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

        // Initialize buffer with spaces
        memset(buffer[i], ' ', CONSOLE_WIDTH);
        buffer[i][CONSOLE_WIDTH] = '\0';
    }

    // Initial width is half the console width
    int initialWidth = CONSOLE_WIDTH / 3;

    // Print tree to buffer
    printTree(root, buffer, height, 0, CONSOLE_WIDTH / 2, initialWidth);

    // Print buffer to console
    for(int i = 0; i < bufferHeight; i++) {
        printf("%s\n", buffer[i]);
    }

    // Free buffer memory
    for(int i = 0; i < bufferHeight; i++) {
        free(buffer[i]);
    }
}

int calculateTreeHeight(NODE *root) {
    if(root == NULL) {
        return 0;
    } else {
        int leftTreeHeight = calculateTreeHeight(root->left);
        int rightTreeHeight = calculateTreeHeight(root->right);

        return (leftTreeHeight > rightTreeHeight) ? (leftTreeHeight + 1) : (rightTreeHeight + 1);
    }
}

void waitForSpaceBar(const char *msg) {
    if(strlen(msg) > 0) {
        printf("%s", msg);
    }

    while(1) {
        int key = getchar();

        if(key == ' ') {
            break;
        }
    }
}

void clearInputBuffer() {
    while(getchar() != '\n');
}

void inputHandle(int arr[], int arrSize, NODE **minRoot, NODE **maxRoot) {
    bool stepMode = false;
    if(arr != NULL) {
        printf("=== ADD NEW NODES ===\n");
        printf("Inserting values: ");
        for(int i = 0; i < arrSize; i++) {
            printf("%d", arr[i]);
            if(i < arrSize - 1) printf(", ");
        }
        printf("\n\n");

        for(int i = 0; i < arrSize; i++) {
            stepMode = true;
            printf("Inserting value %d...\n", arr[i]);

            *minRoot = insertMinHeap(*minRoot, arr[i], &stepMode);

            *maxRoot = insertMaxHeap(*maxRoot, arr[i], &stepMode);
            displayBothHeaps(*minRoot, *maxRoot);

            printf("SUCCESS: node added!\n");
            printf("Press any key to continue...\n");
            //getch();
        }
    }
}

void displayBothHeaps(NODE *minRoot, NODE *maxRoot) {
    printf("A. MIN HEAP                                               B. MAX HEAP\n");

    int minHeight = calculateTreeHeight(minRoot);
    int maxHeight = calculateTreeHeight(maxRoot);
    int height = (minHeight > maxHeight) ? minHeight : maxHeight;
    int bufferHeight = height * 2 - 1; // Include space for branch lines
    
    // Ensure buffer height fits console
    if(bufferHeight > CONSOLE_HEIGHT - 5) {
        bufferHeight = CONSOLE_HEIGHT - 5; // Leave room for menu and prompts
    }
    
    // Ensure at least one line for display
    if (bufferHeight < 1) {
        bufferHeight = 1;
    }
    
    // Create and initialize buffers for both heaps
    char *minBuffer[bufferHeight];
    char *maxBuffer[bufferHeight];
    
    for(int i = 0; i < bufferHeight; i++) {
        minBuffer[i] = (char*)malloc(sizeof(char) * (CONSOLE_WIDTH/2 + 1));
        maxBuffer[i] = (char*)malloc(sizeof(char) * (CONSOLE_WIDTH/2 + 1));
        
        if (minBuffer[i] == NULL || maxBuffer[i] == NULL) {
            printf("ERROR: Memory allocation failed for display buffer!\n\n");
            
            // Free previously allocated buffers
            for (int j = 0; j < i; j++) {
                if (minBuffer[j]) free(minBuffer[j]);
                if (maxBuffer[j]) free(maxBuffer[j]);
            }
            return;
        }
        
        // Initialize buffers with spaces
        memset(minBuffer[i], ' ', CONSOLE_WIDTH/2);
        memset(maxBuffer[i], ' ', CONSOLE_WIDTH/2);
        minBuffer[i][CONSOLE_WIDTH/2] = '\0';
        maxBuffer[i][CONSOLE_WIDTH/2] = '\0';
    }
    
    // Initial width is 1/4 of the console width for each heap
    int initialWidth = CONSOLE_WIDTH / 6;
    
    // Print trees to buffers - ensure center alignment
    if (minRoot) {
        printTree(minRoot, minBuffer, minHeight, 0, CONSOLE_WIDTH/4, initialWidth);
    } else {
        printf("Min Heap is empty!\n");
    }
    
    if (maxRoot) {
        printTree(maxRoot, maxBuffer, maxHeight, 0, CONSOLE_WIDTH/4, initialWidth);
    } else {
        printf("Max Heap is empty!\n");
    }
    
    // Print buffers side by side to console
    for(int i = 0; i < bufferHeight; i++) {
        printf("%s     %s\n", minBuffer[i], maxBuffer[i]);
    }
    
    // Free buffer memory
    for(int i = 0; i < bufferHeight; i++) {
        free(minBuffer[i]);
        free(maxBuffer[i]);
    }
}
