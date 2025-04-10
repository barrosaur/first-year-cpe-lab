#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

void displayMenu() {
    printf("[1] - Add node\n");
    printf("[2] - Delete node\n");
    printf("[3] - Search node\n");
    printf("[4] - Exit\n");
}

void clearInputBuffer() {
    while(getchar() != '\n');
}

void freeTree(NODE *root) {
    if(root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        freeTree(root);
    }
}

// potential bug but im not sure
void waitForSpaceBar(const char *msg) {
    if(strlen(msg) > 0) {
        printf("%s", msg);
    }
    
    while(1) {
        int key = getch();

        if(key == ' ') {
            break;
        }
    }
}

// potential bug but im not sure
void inputHandle(int arr[], int arrSize, NODE **root) {
    bool stepMode = false;
    if(arr != NULL) {

        for(int i = 0; i < arrSize; i++) {
            stepMode = true;
            *root = insert(*root, arr[i], &stepMode);
        }

    }
}