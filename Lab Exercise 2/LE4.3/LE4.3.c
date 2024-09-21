#include <stdio.h>

int main() {
    float firstMark, secondMark, thirdMark, fourthMark;
    float finalGrade;

    printf("=================================================\n");

    printf("1st Mark        : ");
    scanf("%f", &firstMark);
    printf("2nd Mark        : ");
    scanf("%f", &secondMark);
    printf("3rd Mark        : ");
    scanf("%f", &thirdMark);
    printf("4th Mark        : ");
    scanf("%f", & fourthMark);

    if (
        (firstMark < 0 || firstMark > 100) ||
        (secondMark < 0 || secondMark > 100) ||
        (thirdMark < 0 || thirdMark > 100) ||
        (fourthMark < 0 || fourthMark > 100)
        ) {
        printf("INVALID INPUT!\n");
    } else {
        finalGrade = (firstMark + secondMark + thirdMark + fourthMark) / 4;

        printf("FINAL GRADE     : %.2f\n", finalGrade);
        printf("=================================================\n");
        if (finalGrade >= 50 && finalGrade <= 100) {
            printf("REMARKS         : PASSED\n");
        } else {
            printf("REMARKS         : FAILED");
        }
    }

    return 0;
}