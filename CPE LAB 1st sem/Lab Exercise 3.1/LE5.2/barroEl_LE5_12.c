/*
============================================================================
 FILE        : barroEl_LE5_12.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : Grants access to the user with the correct password
 COPYRIGHT   : created
 REVISION HISTORY
 Date:              By: 	                    Description:
 10/01/24	        Ellaine Joyce Barro         Made the entire program
 10/03/24           Ellaine Joyce Barro         Documentation
============================================================================
*/

#include <stdio.h>

//INITIALIZE CORRECT_PASSCODE
#define CORRECT_PASSCODE 123456


 /*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Computes the average of Even Numbers and the product of odd numbers
 ARGUMENTS   : None
 RETURNS     : int
 		       Program successful execution without errors
===========================================================================
*/
int main() {
    int passcodePrompt;
    //INITIALIZE attempt to 0
    int attempt = 0;
    int inputStatus;

    //WHILE attempt is less than 3
    while (attempt < 3) {
        //GET passcodePrompt
        printf("Enter 6-digit PIN: ");
        inputStatus = scanf("%d", &passcodePrompt);

        // If input is not a valid integer, clear the buffer and prompt again
        if (inputStatus != 1) {
            printf("Invalid input. Please enter a valid 6-digit PIN.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;  // Skip the rest of the loop and retry
        }

        //CHECK value of passcodePrompt
        if (passcodePrompt == CORRECT_PASSCODE) {
            //DISPLAY "ACCESS GRANTED!"
            printf("ACCESS GRANTED!");
            return 0;
        } else {
            //INCREMENT attempt by 1
            attempt++;

            //CHECK value of attempt
            if(attempt < 3) {
                //DISPLAY "Invalid password. Try again."
                printf("Invalid password. Try again.\n");
            }
        }
    }

    //DISPLAY "ACCESS DENIED"
    printf("ACCESS DENIED!");

    return 0;
}
