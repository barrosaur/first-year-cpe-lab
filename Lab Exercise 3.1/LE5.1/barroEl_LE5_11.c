#include <stdio.h>

int main () {
    int num, i;
    int evenCount = 0, sumEven = 0;
    int productOdd = 1, oddCount = 0;
    float averageEven;

    printf("======================================================\n");

    for (i = 1; i <= 10; i++) {
        printf("Enter integer %d: ", i);
        scanf("%d", &num);

        if(num % 2 == 0) {
            evenCount++;
            sumEven = sumEven + num;
        } else {
            oddCount++;
            productOdd *= num;
        }
    }

    printf("======================================================\n");

    if(evenCount > 0) {
        averageEven = (float) sumEven / (float) evenCount;
        printf("Average of even numbers: %.2f\n", averageEven);
    } else {
        printf("There are no even numbers.\n");
    }

    if(oddCount == 0) {
        printf("There are no odd numbers.\n");
    } else {
        printf("Product of odd numbers: %d\n", productOdd);
    }

    return 0;
}
