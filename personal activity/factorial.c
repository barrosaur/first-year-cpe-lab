#include <stdio.h>

int factorial(int n);

int main() {
    int num;
    int result;

    printf("Enter Number: ");
    scanf("%d", &num);

    result = factorial(num);

    printf("The factorial of %d is %d", num, result);

    return 0;
}

int factorial(int n) {
    int i;
    int result = 1;

    for(i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}