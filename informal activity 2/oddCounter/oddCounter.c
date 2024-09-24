//make a program that will determine how many odd numbers
//there are from numbers 1 to n

#include <stdio.h>

int main() {
    int i, n, oddCounter = 0;

    printf("Enter limit: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        if(i % 2 != 0) {
            oddCounter++;
        }
    }

    printf("Odd count: %d\n", oddCounter);

    return 0;
}