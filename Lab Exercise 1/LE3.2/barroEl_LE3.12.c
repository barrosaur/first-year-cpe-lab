/*
============================================================================
 FILE        : addDigits.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : Given an integer, sumt its last two digits
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 09/10/24	         Ellaine Joyce Barro        Made the entire program

============================================================================
*/

#include <stdio.h>

 /*
============================================================================
 FUNCTION    : main
 DESCRIPTION : It sums up the last two digits of an integer
 ARGUMENTS   : None
 RETURNS     : integer
 		       Returns 0, program is executed without errors
===========================================================================
*/
int main() {

    int num, sum;
    int lastDigit, secondLastDigit;
    
    printf("Enter number: ");
    scanf("%d", &num);

    //lastDigit is dividing num by 10 and returns the remainder -- last digit
    lastDigit = num % 10;

    /*secondLastDigit will divide num by 100 and returns the remainder
      which then subtracts it to the last digit
      dividing it by 10 
    */
    secondLastDigit = (num % 100 - lastDigit)/10;

    sum = secondLastDigit + lastDigit;

    printf("Sum: %d + %d = %d", secondLastDigit, lastDigit, sum);

    return 0;
    
}