#include <stdio.h>
#include <conio.h>
#include "../tree.h"

void appendNodeModule(NODE **minRoot, NODE **maxRoot) {
    int value;
    char ch;
    bool stepMode = true;

    printf("=== ADDING A NODE ===\n");

    while(1) {
        printf("Enter value: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {
            printf("Inserting value %d...\n", value);

            *minRoot = insertMinHeap(*minRoot, value, &stepMode);

            *maxRoot = insertMaxHeap(*maxRoot, value, &stepMode);

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