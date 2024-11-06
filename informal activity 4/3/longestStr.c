#include <stdio.h>
#include <string.h>

int findMaxLength(char str[], char longestStr[], int currentMaxLength);
void printLongestStr(char longestStr[], int maxLength);

int main() {
    char str[100];
    char longestStr[100];
    int maxLength = 0;
    int i;

    for (i = 1; i <= 5; i++) {
        printf("Enter String %d: ", i);
        gets(str);

        maxLength = findMaxLength(str, longestStr, maxLength);
    }

    printLongestStr(longestStr, maxLength);

    return 0;
}

int findMaxLength(char str[], char longestStr[], int currentMaxLength) {
    if(strlen(str) > currentMaxLength) {
        strcpy(longestStr, str);
        return strlen(str);
    }
    return currentMaxLength;
}

void printLongestStr(char longestStr[], int maxLength) {
    printf("The longest string is %s with %d characters.\n", longestStr, maxLength);
}