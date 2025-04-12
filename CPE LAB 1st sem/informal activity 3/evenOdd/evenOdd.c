//MODULARIZATION determine if number is even or odd

#include <stdio.h> 

void determineEvenOdd(int num);

int main() {
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    determineEvenOdd(num);

    return 0;
}

void determineEvenOdd(int num) {
    if (num % 2 == 0) {
        printf("%d is even.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }
}