#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

void mainMenu(TREENODE **root) {
    int choice;
    bool running = true;

    while (running) {
        printf("\n--- AVL Tree Menu ---\n");
        printf("1. Append Node\n");
        printf("2. Browse Tree\n");
        printf("3. Change Node\n");
        printf("4. Delete Node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        while(getchar() != '\n'); // Clear input buffer

        switch(choice) {
            case 1:
                appendModule(root);
                break;
            case 2:
                browseModule(*root);
                break;
            case 3:
                changeModule(root);
                break;
            case 4:
                deleteModule(root);
                break;
            case 5:
                running = false;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void browseModule(TREENODE *root) {
    int choice;
    
    printf("\n--- Browse Tree ---\n");
    printf("1. Display Tree\n");
    printf("2. Breadth First Traversal\n");
    printf("Enter choice: ");
    
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear input buffer

    switch(choice) {
        case 1:
            displayTree(root);
            break;
        case 2:
            breadthFirstTraversal(root);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void appendModule(TREENODE **root) {
    int value;
    printf("Enter value to append: ");
    
    if (scanf("%d", &value) != 1) {
        printf("Invalid input.\n");
        while(getchar() != '\n'); // Clear input buffer
        return;
    }
    while(getchar() != '\n'); // Clear input buffer

    *root = insertNode(*root, value);
    printf("Value %d appended successfully.\n", value);
    displayTree(*root);
}