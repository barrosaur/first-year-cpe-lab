#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

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