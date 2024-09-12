/*
============================================================================
 FILE        : tuitionFee.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : Compute the tuition fee of the first and second semester and their total fee
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 09/12/24	         Ellaine Joyce Barro        Made the entire program

============================================================================
*/

#include <stdio.h>

#define REGISTRATION_FEE 450
#define PRICE_PER_UNIT 450
#define PENALTY 2260

 /*
============================================================================
 FUNCTION    : main
 DESCRIPTION : It computes the tuition fee of the first and second semester and their total tuition fee
 ARGUMENTS   : None
 RETURNS     : integer
 		       Returns 0, program is executed without errors
===========================================================================
*/

int main () {
    int firstSemUnits, secondSemUnits;
    float firstSemFee, secondSemFee, sum;

    //GET units for first semeseter and second semester
    printf("1st Semester Number of Units: ");
    scanf("%d", &firstSemUnits);
    printf("2nd Semester Number of Units: ");
    scanf("%d", &secondSemUnits);

    //COMPUTE first and second semester fee
    firstSemFee = REGISTRATION_FEE + (PRICE_PER_UNIT * firstSemUnits) + (firstSemUnits * 2260)/12;
    secondSemFee = REGISTRATION_FEE + (PRICE_PER_UNIT * secondSemUnits) + (secondSemUnits * 2260)/12;

    //COMPUTE sum of first and second semester fees
    sum = firstSemFee + secondSemFee;

    //DISPLAY the results
    printf("1st Semester Tuition Fee    : %.2f\n", firstSemFee);
    printf("2nd Semester Tuition Fee    : %.2f\n", secondSemFee);
    printf("Total Tuition Fee           : %.2f\n", sum);

    return 0;
}