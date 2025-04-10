#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

void waitForSpaceBar(const char* message) {
    if (strlen(message) > 0) {
        printf("%s", message);
    }
    
    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    // Wait for space bar
    while (1) {
        c = getchar();
        if (c == ' ' || c == '\n') {
            break;
        }
    }
}