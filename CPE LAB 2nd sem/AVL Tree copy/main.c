#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"

void pauseAndClear() {
    printf("\nPress Enter to continue...");
    while(getchar() != '\n');
    system("clear || cls");
}

void stepByStepTreeCreation(TREENODE **root, Input input) {
    printf("Building AVL Tree Step by Step...\n");
    printf("Press SPACE to continue each step, '!' to finish.\n");

    for (int i = 0; i < input.size; i++) {
        printf("\nInserting %d\n", input.arr[i]);
        
        // Wait for spacebar
        int ch;
        while ((ch = getchar()) != ' ' && ch != '!') {
            if (ch == EOF) break;
        }

        if (ch == '!') break;

        *root = insertNode(*root, input.arr[i]);
        displayTree(*root);
    }
}

int main() {
    TREENODE *root = NULL;
    Input input;

    // Input Numbers
    input = inputModule();

    if (input.arr == NULL || input.size == 0) {
        printf("No valid input received.\n");
        return 1;
    }

    // Step by Step Tree Creation
    stepByStepTreeCreation(&root, input);

    // Free input array after using
    free(input.arr);

    // Main Menu
    mainMenu(&root);

    // Free the tree before exiting
    freeTree(root);

    return 0;
}