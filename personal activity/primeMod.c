#include <stdio.h>

int isPrime(int num);

int main() {
    int num, result;

    printf("Enter a number: ");
    scanf("%d", &num);

    result = isPrime(num);

    if(result == 0) {
        printf("%d is not a prime number.\n", num);
    } else {
        printf("%d is a prime number.\n", num);
    }

    return 0;
}

int isPrime(int num) {
    int i;

    if (num <= 0) {
        return 0; // not a prime
    }

    for(i = 2; i*i <= num; i++) {
        return 0; // not a prime
    }
    return 1; // prime
}