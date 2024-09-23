/*
============================================================================
 FILE        : barroEl_LE4.13.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : The program computes the final grade
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                     Description:
 09/22/24	         Ellaine Joyce Barro         Made the entire program
============================================================================
*/

#include <stdio.h>

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Checks whether user input is a consonant, vowel, or invalid
 ARGUMENTS   : None
 RETURNS     : int
 		       Program successful execution without errors
===========================================================================
*/

int main() {
    float firstMark, secondMark, thirdMark, fourthMark;
    float finalGrade;

    printf("=================================================\n");

    //GETS all four marks
    printf("1st Mark        : ");
    scanf("%f", &firstMark);
    printf("2nd Mark        : ");
    scanf("%f", &secondMark);
    printf("3rd Mark        : ");
    scanf("%f", &thirdMark);
    printf("4th Mark        : ");
    scanf("%f", & fourthMark);

    //CHECK each input if it is within range
    if (
        (firstMark < 0 || firstMark > 100) ||
        (secondMark < 0 || secondMark > 100) ||
        (thirdMark < 0 || thirdMark > 100) ||
        (fourthMark < 0 || fourthMark > 100)
        ) {
        //IF not, then 
        //  DISPLAY "INVALID INPUT!"
        printf("INVALID INPUT!\n");
    } else {
        //ELSE
        //  COMPUTE for finalGrade
        finalGrade = (firstMark + secondMark + thirdMark + fourthMark) / 4;

        //DISPLAY finalGrade
        printf("FINAL GRADE     : %.2f\n", finalGrade);
        printf("=================================================\n");
        
        //CHECK value of finalGrade
        if (finalGrade >= 50 && finalGrade <= 100) {
            //IF finalGrade is between 50 and 100, THEN
            //  DISPLAY "REMARKS: PASSED"
            printf("REMARKS         : PASSED\n");
        } else {
            //ELSE
            //  DISPLAY "REMARKS: PASSED"
            printf("REMARKS         : FAILED");
        }
    }

    return 0;

}