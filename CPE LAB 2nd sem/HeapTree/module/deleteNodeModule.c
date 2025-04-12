#include <stdio.h>
#include <conio.h>
#include "../tree.h"

void deleteNodeModule(NODE **minRoot, NODE **maxRoot) {
    bool stepMode = true;

    printf("=== DELETE NODE ===\n");
    
    displayBothHeaps(*minRoot, *maxRoot);
    
    if (*minRoot == NULL && *maxRoot == NULL) {
        printf("ERROR: Both heaps are empty!\n");
        printf("Press any key to return to MAIN MENU...\n");
        //getch();
        return;
    }
    
    printf("Deleting root nodes...\n");
    
    if (*minRoot != NULL) {
        printf("Min Heap root: %d\n", (*minRoot)->value);
        *minRoot = deleteMinHeap(*minRoot, &stepMode);
    } else {
        printf("Min Heap is empty, nothing to delete.\n");
    }
    
    if (*maxRoot != NULL) {
        printf("Max Heap root: %d\n", (*maxRoot)->value);
        *maxRoot = deleteMaxHeap(*maxRoot, &stepMode);
    } else {
        printf("Max Heap is empty, nothing to delete.\n");
    }
    
    displayBothHeaps(*minRoot, *maxRoot);
    
    printf("Press any key to return to MAIN MENU...\n");
    getch();

    return;
}