#include <stdio.h>
#include "../tree.h"

void inputHandle(int arr[], int arrSize, NODE **minRoot, NODE **maxRoot) {
    bool stepMode = false;
    if(arr != NULL) {
        printf("Inserting values...\n");
        for(int i = 0; i < arrSize; i++) {
            printf("%d", arr[i]);
            if(i < arrSize - 1) printf(", ");
        }
        printf("\n\n");

        for(int i = 0; i < arrSize; i++) {
            stepMode = true;
            printf("Inserting %d...\n", arr[i]);

            *minRoot = insertMinHeap(*minRoot, arr[i], &stepMode);
            *maxRoot = insertMaxHeap(*maxRoot, arr[i], &stepMode);
            displayBothHeaps(*minRoot, *maxRoot);

            printf("SUCCESS: node added!\n");
            printf("Press any key to continue...\n\n");
        }
    }
}