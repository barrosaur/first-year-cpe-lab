//MODULARIZATION determine if character inputted lowercase by displaying Y or N
#include <stdio.h>

void determineLowercase(char charac);

int main() {
    char character;

    printf("Enter character: ");
    scanf("%c", &character);

    determineLowercase(character);

    return 0;
}

void determineLowercase(char charac) {
    if(charac >= 'a' && charac <= 'z') {
        printf("Y\n");
    } else if (charac >= 'A' && charac <= 'Z') {
        printf("N\n");
    } else {
        printf("Invalid Input.\n");
    }
}