// make a program that will display the even numbers from 1 to n

#include <stdio.h>

int main () {
    int i, n;

    printf("Enter limit (n): ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}