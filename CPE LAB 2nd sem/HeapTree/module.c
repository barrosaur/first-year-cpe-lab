#include <stdio.h>
#include <conio.h>
#include "tree.h"

void appendNodeModule(NODE **minRoot, NODE **maxRoot) {
    int value;
    char ch;
    bool stepMode = true;

    printf("=== ADDING A NODE ===\n");

    while(1) {
        printf("Enter value: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {
            // call insert function here
            printf("Inserting value %d...\n", value);

            // Insert into min heap
            *minRoot = insertMinHeap(*minRoot, value, &stepMode);

            // Insert into max heap
            *maxRoot = insertMaxHeap(*maxRoot, value, &stepMode);

            // Display both heaps after insertion
            displayBothHeaps(*minRoot, *maxRoot);

            printf("SUCCESS: node added!\n");
            printf("Press any key to return to MAIN MENU...\n");
            getch();

            break;
        } else {
            printf("ERROR: value is of type int!\n\n");
            clearInputBuffer();
        }
    }

    return;
}

void deleteNodeModule(NODE **minRoot, NODE **maxRoot) {
    bool stepMode = true;

    printf("=== DELETE NODE ===\n");

    displayBothHeaps(*minRoot, *maxRoot);

    if (*minRoot == NULL || *maxRoot == NULL) {
        printf("ERROR: One or both heaps are empty!\n");
        printf("Press any key to return to MAIN MENU...\n");
        getch();
        return;
    }

    printf("Deleting root nodes from both heaps...\n");
    printf("Min Heap root: %d, Max Heap root: %d\n", (*minRoot)->value, (*maxRoot)->value);

    *minRoot = deleteMinHeap(*minRoot, &stepMode);

    *maxRoot = deleteMaxHeap(*maxRoot, &stepMode);

    displayBothHeaps(*minRoot, *maxRoot);

    printf("SUCCESS: nodes removed!\n");
    printf("Press any key to return to MAIN MENU...\n");
    getch();

    return;
}
