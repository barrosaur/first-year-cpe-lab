    #include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void) {

    NODE* root = NULL;
    int choice, value;
    bool found, stepMode;
    
    // Input initial values
    INPUT input = inputModule();
    
    if (input.arr != NULL) {
        // Insert initial values into the tree without animation first
        for (int i = 0; i < input.size; i++) {
            stepMode = true; // Don't show steps for initial insertion
            root = insert(root, input.arr[i], &stepMode);
        }
        
        printf("Initial tree:\n");
        displayTree(root);
        waitForSpaceBar("Press SPACE BAR key to continue to main menu...");
        
        int c;
        // Clear input buffer
        while ((c = getchar()) != '\n' && c != EOF);
        
        // Wait for space bar
        c = getchar();

        free(input.arr); // Free the input array
    }
    
    do {
        printf("=== SPLAY MAIN MENU ===\n");
        printf("[1] Add nodes\n");
        printf("[2] Delete a node\n");
        printf("[3] Search a node\n");
        printf("[4] Exit\n");
        printf("Choice? ");
        
        if (scanf("%d", &choice) != 1) {
            // Handle invalid input
            printf("Invalid input. Please enter a number.\n");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }
        
        getchar(); // Clear the input buffer
        
        switch (choice) {
            case 1: 
                printf("=== ADD NODEs ===\n");
                printf("Insert value to add: ");
                scanf("%d", &value);
                getchar(); // Clear the buffer
                
                // Display current tree before splaying
                displayTree(root);
                
                // Insert with step-by-step splaying
                stepMode = true;
                root = insert(root, value, &stepMode);
                
                printf("SUCCESS: node added\n");
                waitForSpaceBar("Press SPACE BAR key to return to MAIN MENU...");
                break;
                
            case 2:
                printf("=== DELETE NODE ===\n");
                printf("Input node to delete: ");
                scanf("%d", &value);
                getchar(); // Clear the buffer
                
                // Display current tree before splaying
                displayTree(root);
                
                // Delete with step-by-step splaying
                stepMode = true;
                root = delete(root, value, &stepMode);
                
                printf("SUCCESS: node removed\n");
                waitForSpaceBar("Press SPACE BAR key to return to MAIN MENU...");
                break;
                
            case 3:
                printf("=== SEARCH NODE ===\n");
                printf("Input node to search: ");
                scanf("%d", &value);
                getchar(); // Clear the buffer
                
                // Display current tree before splaying
                displayTree(root);
                
                // Search with step-by-step splaying
                stepMode = true;
                found = false;
                root = search(root, value, &found, &stepMode);
                
                if (found) {
                    printf("Node %d found, splaying %d, press any SPACE BAR key to continue...\n", value, value);
                    waitForSpaceBar("");
                    displayTree(root);
                }
                
                waitForSpaceBar("Press SPACE BAR key to return to MAIN MENU...");
                break;
                
            case 4: // Exit
                printf("Exiting program...\n");
                freeTree(root);
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                waitForSpaceBar("Press SPACE BAR key to continue...");
        }
        
    } while (choice != 4);
    
    // Free the tree before exiting
    freeTree(root);
    
    return 0;
}