// Enter 5 integers: 10 20 30 40 50
// ==========================================
// Array Elements: 10 20 30 40 50
// Sum: 150
// Average: 30.0

#include <stdio.h>

int main() {
    int arr[5];
    int *ptr = arr; //first element of the array
    int sum = 0; 
    float average;

    printf("Enter 5 integers: ");
    for(int i = 0; i < 5; i++) {
        scanf("%d", (ptr + i)); // storing
    }

    //calculate the sum using pointers
    for(int i = 0; i < 5; i++) {
        sum += *(ptr + i); //pointing
    }

    //calculate the average
    average = (float) sum / 5;

    //display 
    printf("Array Elements: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    
    printf("Sum: %d", sum);
    printf("Average: %.2f", average);

    return 0;
}