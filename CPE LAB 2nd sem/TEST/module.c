#include <stdio.h>
#include "tree.h"

void addNodeModule(NODE **root) {
    printf("=== ADD A NODE ===\n");

    int value;
    char ch;
    bool stepMode = false;

    while(1) {
        printf("Enter a value to insert: ");
        if((scanf("%d%c", &value, &ch)) ==  2 && ch == '\n') {
            displayTree(*root);
            
            stepMode = true;
            *root = insert(*root, value, &stepMode);

            if(*root != NULL) {
                printf("SUCCESS: node added!\n\n");
                waitForSpaceBar("Press SPACE BAR to continue...\n");
            } else {
                printf("ERROR: node not added!\n\n");
            }

            break;
        } else {
            printf("ERROR: value is of type int!\n\n");
            clearInputBuffer();
        }
    }

}

void deleteNodeModule(NODE **root) {
    printf("=== DELETE A NODE ===\n");

    int value;
    char ch;
    bool stepMode = false;

    while(1) {
        printf("Enter node to delete: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {
            displayTree(*root);
            
            stepMode = true;
            if(delete(*root, value, &stepMode) != NULL) {
                printf("SUCCESS: node deleted!\n\n");
                waitForSpaceBar("Press SPACE BAR to continue...\n");
            }

            break;
        } else {
            printf("ERROR: value is of type int!\n\n");
            clearInputBuffer();
        }
    }
}

void searchNodeModule(NODE **root) {
    printf("=== SEARCH A NODE ===\n");

    int value;
    char ch;
    bool found = false;
    bool stepMode = false;

    while(1) {
        printf("Enter value: ");
        if((scanf("%d%c", &value, &ch)) == 2 && ch == '\n') {
            stepMode = true;

            displayTree(*root);

            if(search(*root, value, &found, &stepMode) != NULL) {
                if(found) {
                    waitForSpaceBar("");
                    displayTree(*root);
                }
                
                waitForSpaceBar("Press SPACE BAR to continue...\n");
            } else {
                printf("ERROR: node not found!\n\n");
            }

            break;
        } else {
            printf("ERROR: value is of type int!\n\n");
            clearInputBuffer();
        }
    }
}