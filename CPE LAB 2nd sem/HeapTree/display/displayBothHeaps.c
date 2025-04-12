#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"

void displayBothHeaps(NODE *minRoot, NODE *maxRoot) {
    printf("A. MIN HEAP                                               B. MAX HEAP\n");

    int minHeight = calculateTreeHeight(minRoot);
    int maxHeight = calculateTreeHeight(maxRoot);
    int height = (minHeight > maxHeight) ? minHeight : maxHeight;
    int bufferHeight = height * 2 - 1;
    
    if(bufferHeight > CONSOLE_HEIGHT - 5) {
        bufferHeight = CONSOLE_HEIGHT - 5; 
    }
    
    if (bufferHeight < 1) {
        bufferHeight = 1;
    }
    
    char *minBuffer[bufferHeight];
    char *maxBuffer[bufferHeight];
    
    for(int i = 0; i < bufferHeight; i++) {
        minBuffer[i] = (char*)malloc(sizeof(char) * (CONSOLE_WIDTH/2 + 1));
        maxBuffer[i] = (char*)malloc(sizeof(char) * (CONSOLE_WIDTH/2 + 1));
        
        if (minBuffer[i] == NULL || maxBuffer[i] == NULL) {
            printf("ERROR: Memory allocation failed for display buffer!\n\n");
            
            for (int j = 0; j < i; j++) {
                if (minBuffer[j]) free(minBuffer[j]);
                if (maxBuffer[j]) free(maxBuffer[j]);
            }
            return;
        }
        
        memset(minBuffer[i], ' ', CONSOLE_WIDTH/2);
        memset(maxBuffer[i], ' ', CONSOLE_WIDTH/2);
        minBuffer[i][CONSOLE_WIDTH/2] = '\0';
        maxBuffer[i][CONSOLE_WIDTH/2] = '\0';
    }
    
    int initialWidth = CONSOLE_WIDTH / 6;
    
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
    
    for(int i = 0; i < bufferHeight; i++) {
        printf("%s     %s\n", minBuffer[i], maxBuffer[i]);
    }
    
    for(int i = 0; i < bufferHeight; i++) {
        free(minBuffer[i]);
        free(maxBuffer[i]);
    }
}