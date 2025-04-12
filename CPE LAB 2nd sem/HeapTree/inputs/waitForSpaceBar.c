#include <stdio.h>
#include <string.h>

void waitForSpaceBar(const char *msg) {
    if(strlen(msg) > 0) {
        printf("%s", msg);
    }

    while(1) {
        int key = getchar();

        if(key == ' ') {
            break;
        }
    }
}