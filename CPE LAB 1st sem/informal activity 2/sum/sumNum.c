//make a program that will compute the sum of n numbers inputted by the user

#include <stdio.h>

int main() {
    int i, n, sum = 0;

    printf("Enter limit (n): ");
    scanf("%d", &n);

    for(i = n; i >= 0; i--) {
        sum += i;
        printf("%d ", i);

        if(i != 0) {
            printf ("+ ");
        }
    }

    printf(" = %d\n", sum);

    return 0;
}