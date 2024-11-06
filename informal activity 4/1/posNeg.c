#include <stdio.h>

int main() {
    int i, num[10];
    int positiveCount = 0, negativeCount = 0, zeroCount = 0;

    for (i = 1; i <= 10; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num[i]);

        if(num[i] == 0) {
            zeroCount++;
        } else if (num[i] > 0) {
            positiveCount++;
        } else {
            negativeCount++;
        }

    }

    printf("\n============================================================\n");

    printf("Positive number count : %d\n", positiveCount);
    printf("Negative number count : %d\n", negativeCount);
    printf("Zero count            : %d\n", zeroCount);
    return 0;
}