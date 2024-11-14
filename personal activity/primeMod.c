#include <stdio.h>

int isPrimeNumber(int n);

int main() {
    int number, isPrime;

    printf("Enter number: ");
    scanf("%d", &number);

    isPrime = isPrimeNumber(number);

    if(isPrime == 1) {
        printf("%d IS a prime number.\n", number);
    } else {
        printf("%d IS NOT a prime number.\n", number);
    }

    return 0;
}

int isPrimeNumber(int n) {
    int i, flag;

    if(n <= 1) {
        flag = 2; //not prime
    } else if (n == 2) {
        flag = 1; //prime
    } else if (n % 2 == 0) {
        flag = 2; //not prime
    } else {
        flag = 1; //assume prime
        for(i = 3; i*i <= n; i += 2) {
            if(n % i == 0) {
                flag = 2; //not prime
                break;
            }
        }
    }

    return flag;
}