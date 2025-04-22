#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void displayMenu();

int main()
{
    int choice;
    char ch;
    NODE *root = createNode();
    
    INPUT input = inputModule();
    inputHandle(input.words, input.size, &root);
    
    for(int i = 0; i < input.size; i++) {
        free(input.words[i]);
    }
    free(input.words);
    
    while(1) {
        displayMenu();
        printf("Enter choice: ");
        if((scanf("%d%c", &choice, &ch)) == 2 && ch == '\n') {
            switch(choice) {
                case 1:
                    insertWordModule(&root);
                    break;
                case 2:
                    searchWordModule(root);
                    break;
                case 3:
                    deleteWordModule(&root);
                    break;
                case 4:
                    printf("Exiting...\n\n");
                    freeTrie(root);
                    return 0;
                default:
                    printf("Invalid option!\n\n");
            }
        } else {
            printf("ERROR: choice is of type int!\n\n");
            clearInputBuffer();
        }
    }
    return 0;
}

void displayMenu() {
    printf("=== TRIE TREE MENU ===\n");
    printf("[1] - Insert word\n");
    printf("[2] - Search word\n");
    printf("[3] - Delete word\n");
    printf("[4] - Exit\n");
}