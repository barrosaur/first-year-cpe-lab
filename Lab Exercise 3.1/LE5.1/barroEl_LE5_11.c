#include <stdio.h>

int main () {
    int num, i;
    int evenCount = 0, sumEven = 0, productOdd = 1;
    float averageEven;

    printf("======================================================\n");

    for (i = 1; i <= 10; i++) {
        printf("Enter integer %d: ", i);
        scanf("%d", &num);

        if(num % 2 == 0) {
            evenCount++;
            sumEven += num;
        } else {
            productOdd *= num;
        }
    }

    printf("======================================================\n");

    averageEven = (float) sumEven / (float) evenCount;

    printf("Average of even numbers: %.2f\n", averageEven);
    printf("Product of odd numbers: %d\n", productOdd);

    return 0;
}
