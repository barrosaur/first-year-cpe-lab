/*
asks for length and width of two triangles. the program should tell the user whether the areas
are the same or which rectangle has the greater area
*/

#include <stdio.h>

int main() {
    int length1, width1, length2, width2;
    int area1, area2;

    //GET length and width of rectangle 1
    printf("Enter length of rectangle 1    :    ");
    scanf("%d", &length1);
    printf("Enter width of rectangle 1     :    ");
    scanf("%d", &width1);
    printf("=============================================\n");

    //GET length and width of rectangle 2
    printf("Enter the legnth of rectangle 2:    ");
    scanf("%d", &length2);
    printf("Enter the width of rectangle 2 :    ");
    scanf("%d", &width2);

    //COMPUTE area1 and area2
    area1 = length1 * width1;
    area2 = length2 * width2;

    if(area1 > area2) {
        printf("The area of the first rectangle: %d is bigger than the second: %d\n.", area1, area2);
    } else if (area2 > area1) {
        printf("The area of the second rectangle: %d is bigger than the first: %d\n.", area2, area1);
    } else {
        printf("The area of the first and second rectangle is equal");
    }

    return 0;
}