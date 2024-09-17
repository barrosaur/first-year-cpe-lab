/*
============================================================================
 FILE        : weeklyPay.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : A program that calculates a user's weekly pay given their yearly pay
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 09/10/24	         Ellaine Joyce Barro        Made the entire program

============================================================================
*/

#include <stdio.h>

#define weeksInAYear 52

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : It calculates the weekly pay given the yearly pay of the user
 ARGUMENTS   : None
				
 RETURNS     : integer
               Returns 0, program is executed without errors
===========================================================================
*/
int main () {

    int userAnnualPay;
    float weeklyPay;

    printf("Enter yearly pay: ");
    scanf("%d", &userAnnualPay);

    //the user's annual pay divided by 52 to get their weekly pay
    weeklyPay = (float)userAnnualPay / weeksInAYear;

    //print output
    printf("Your weekly pay is: %.2f\n", weeklyPay);

    return 0;
}