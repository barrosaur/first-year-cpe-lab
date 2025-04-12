/*
============================================================================
 FILE        : barroEl_LE8_11.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : Given an integer, the program prints the associated day
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                    Description:
 11/26/24	         Ellaine Joyce A. Barro     Made the entire program.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

char *getDayOfWeek(int day);
void displayDay(int day);
void clearInputBuffer(int input);

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Executes the main program
 ARGUMENTS   : None 
 RETURNS     : int - successful program execution
===========================================================================
*/
int main() {
    int day;
    char c;

    while(1) {
        printf("Enter day: ");
        if(scanf("%d%c", &day, &c) == 2 && c == '\n') {
            if(day != 0) {
                displayDay(day);
                break;
            }
        } else {
            printf("Invalid input!\n");
            clearInputBuffer(day);
        }
    }


    return 0; 
}

/*
============================================================================
 FUNCTION    : *getDaysOfWeek
 DESCRIPTION : Returns days of the week given an integer
 ARGUMENTS   : int day - the integer assosciated with the day
 RETURNS     : string  - the day or invalid
===========================================================================
*/
char *getDayOfWeek(int day) {
    char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    if(day >= 1 && day <= 7) {
        return days[day - 1];
    } else {
        return "INVALID";
    }

}

/*
============================================================================
 FUNCTION    : displayDay
 DESCRIPTION : Displays which day associated with its integer
 ARGUMENTS   : int day - the integer assosciated with the day
 RETURNS     : void
===========================================================================
*/
void displayDay(int day) {
    char *dayName = getDayOfWeek(day);
    printf("Day of the week: %s\n", dayName);
    return;
}

void clearInputBuffer(int input) {
    while((input = getchar()) != '\n');
}