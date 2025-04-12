//MODULARIZATION determine student's final grade and indicate whether passing or failing 
#include <stdio.h>

int main() {
    float firstMark, secondMark, thirdMark, fourthMark;
    float finalGrade;
    
    printf("Enter 1st Mark: ");
    scanf("%f", &firstMark);
    printf("Enter 2nd Mark: ");
    scanf("%f", &secondMark);
    printf("Enter 3rd Mark: ");
    scanf("%f", &thirdMark);
    printf("Enter 4th Mark: ");
    scanf("%f", &fourthMark);

    if(
        (firstMark < 0 || firstMark > 100) ||
        (secondMark < 0 || secondMark > 100) ||
        (thirdMark < 0 || thirdMark > 100) ||
        (fourthMark < 0 || fourthMark > 100)
    ) {
        printf("Invalid Input\n");
    } else {
        finalGrade = (firstMark + secondMark + thirdMark + fourthMark) / 4;
        printf("Final Grade: %.2f\t", finalGrade);

        if(finalGrade >= 50 && finalGrade <= 100) {
            printf("PASSING.\n");
        } else {
            printf("FAILING.\n");
        }
    }

    return 0;
}