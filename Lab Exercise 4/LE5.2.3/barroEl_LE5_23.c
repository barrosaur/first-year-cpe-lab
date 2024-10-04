#include <stdio.h>

int main() {
    int firstNum = 1, secondNum = 1, nextNum, i;
    int limit;
    char charInputCheck;

    printf("Enter limit: ");

    while(scanf("%d", &limit) != 1 || limit < 1 ) {
        while((charInputCheck = getchar()) != '\n');
        printf("Invalid Input! Please enter a number greater than 0: ");
    }

    printf("========================================================================\n");

    printf("FIBONACCI SEQUENCE\n");

    if(limit == 1) {
        printf("%d\n", firstNum);
        return 0;
    }

    printf("%d %d ", firstNum, secondNum);

    for(i = 3; i<= limit; i++) {
        nextNum = firstNum + secondNum;
        printf("%d ", nextNum);
        firstNum = secondNum;
        secondNum = nextNum;
    }

    printf("\n");

    return 0;
}