#include <stdio.h>

int main() {
    char str[3][20];

    for(int i = 0; i < 3; i++) {
        printf("Enter string #%d: ", i+1);
        gets(str[i]);
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%s", str[i]);
        }
        printf("\n");
    }

    return 0;
}