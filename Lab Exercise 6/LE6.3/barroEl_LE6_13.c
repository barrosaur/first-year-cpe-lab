/*
============================================================================
 FILE        : barroEl_LE6_12.c
 AUTHOR      : Ellaine Joyce A. Barro
             : Mark Steven Tsai V. Go
 DESCRIPTION : Problem Solver Menu; it solves for a factorial, power, and quadratic problem
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                        Description:
 10/29/24	         Ellaine Joyce A. Barro         Made the entire program
                     Mark Steven Tsai V. Go     
============================================================================
*/
#include <stdio.h>
#include <math.h>

void displayMenu();
int powerSolver(int base, int p);
int factorialSolver(int num);
int quadraticSolver(int a, int b, int c);

float root1, root2;
/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Executes the program
 ARGUMENTS   : None
 RETURNS     : int - successful program execution
===========================================================================
*/
int main() {
    //var declaration
    int choice = 0;

    while (choice != 4) {

        displayMenu();
        printf("\nEnter choice: ");
        if((scanf("%d", &choice)) != 1) {
            printf("Invalid Operation.\n");

            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1: {
                int base, power, result;
                printf("Enter base: ");
                scanf("%d", &base);
                printf("Enter power: ");
                scanf("%d", &power);

                result = powerSolver(base, power);
                printf("The reuslt is: %d\n", result);
                break;
            }
            case 2: {
                int num, result;
                printf("Enter a number: ");
                scanf("%d", &num);
                result = factorialSolver(num);
                printf("The factorial of %d is: %d\n", num, result);
                break;
            }
            case 3: {
                int a, b, c;
                int result;

                printf("Enter a: ");
                scanf("%d", &a);
                printf("Enter b: ");
                scanf("%d", &b);
                printf("Enter c: ");
                scanf("%d", &c);

                result = quadraticSolver(a, b, c);
                if(result == 1) {
                    printf("There is no solution.\n");
                } else if (result == 2) {
                    printf("Root: %.2f\n", root1);
                } else if (result == 3) {
                    printf("There are no real roots.\n");
                } else if (result == 4) {
                    printf("The roots are: %.2f and %.2f\n", root1, root2);
                }
                break;
            }
            case 4: {
                printf("Exiting...");
                return 0; //exit
            }
            default: {
                printf("Invalid option.\n");
            }
        }
    }

    return 0;
}

/*
============================================================================
 FUNCTION    : displayMenu
 DESCRIPTION : Displays the menu for the problem solver
 ARGUMENTS   : None
 RETURNS     : None
===========================================================================
*/
void displayMenu() {
    printf("\nChoose an option\n");
    printf("1. Power Problem Solver\n");
    printf("2. Factorial Problem Solver\n");
    printf("3. Quadratic Problem Solver\n");
    printf("4. Exit\n");

    return;
}

/*
============================================================================
 FUNCTION    : powerSolver
 DESCRIPTION : Given the base and power, it solves for the base raised to the power 
 ARGUMENTS   : int base - this is the base number inputted by the user
               int p -  this is the power or exponent inputted by the user
 RETURNS     : int - returns the result of the base raised to the power
===========================================================================
*/
int powerSolver(int base, int p) {
    return pow(base, p);
}

/*
============================================================================
 FUNCTION    : factorialSolver
 DESCRIPTION : Given a number, it solves for the factorial of that number
 ARGUMENTS   : int num - this is the number inputted by the user
 RETURNS     : int - it returns the result of the factorial of the number
===========================================================================
*/
int factorialSolver(int num) {
    int result = 1, i;
    for(i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

/*
============================================================================
 FUNCTION    : quadraticSolver
 DESCRIPTION : Solves for the roots of a quadratic equation of the form ax^2 + bx + c = 0
 ARGUMENTS   : int a - the first constant of the equation
               int b - the second constant of the equation
               int c - the third constant of the equation 
 RETURNS     : int - returns the roots or if it has no solution or if it has no roots
===========================================================================
*/
int quadraticSolver(int a, int b, int c) {
    int discriminant;
    int returnFlag;

    //1 - There is no solution
    //2 - root1 -c/b
    //3 - There are no real roots
    //4 - root1 and root2

    if(a == 0 && b == 0) {
        returnFlag = 1;

    } else if (a == 0) {
        root1 = -(float)c/b;
        returnFlag = 2;
    } else {
        discriminant = (b*b) - (4*a*c);
        if (discriminant < 0) {
            returnFlag = 3;
        } else {
            returnFlag = 4;
            root1 = (-b + sqrt(discriminant)) / (2*a);
            root2 = (-b - sqrt(discriminant)) / (2*a);
        }
    }

    return returnFlag;
}