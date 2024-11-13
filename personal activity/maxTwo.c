#include <stdio.h>

int findMax(int num1, int num2);

int main() {
    int num1, num2;
    int result;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    result = findMax(num1, num2);

    if(result == 1) {
        printf("%d and %d are equal.\n", num1, num2);
    } else if (result == num1) {
        printf("%d > %d\n", num1, num2);
    } else {
        printf("%d > %d\n", num2, num1);
    }

    return 0;
}

int findMax(int num1, int num2) {
    if(num1 > num2) {
        return num1;
    } else if (num1 < num2) {
        return num2;
    } else {
        return 1;
    }
}