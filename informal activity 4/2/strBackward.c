#include <stdio.h>
#include <string.h>

int main() {
    char string[50];
    int length, i;

    printf("Enter a string: ");
    gets(string);

    length = strlen(string);

    for(i = length; i >= 0; i--) {
        printf("%c ", string[i]);
    }
    
    return 0;
}