//determine largest of the two numbers

#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    if (num1 > num2) {
        printf("%d is bigger than %d", num1, num2);
    } else if (num2 > num1) {
        printf("%d is bigger than %d", num2, num1);
    } else {
        printf("Both numbers are equal");
    }

    return 0;
}