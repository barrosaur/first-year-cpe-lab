/*
============================================================================
 FILE        : barroEl_LE5_13.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : Problem solver
 COPYRIGHT   : created
 REVISION HISTORY
 Date:              By: 	                    Description:
 10/01/24	        Ellaine Joyce Barro         Made the entire program
 10/03/24           Ellaine Joyce Barro         Documentation
============================================================================
*/

#include <stdio.h>
#include <math.h>

float powerProblemSolver(float base, float power);
int factorialProblemSolver(int x);
void rootsProblemSolver(float a, float b, float c);

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Displays 4 operations on what the user wants to be solved
 ARGUMENTS   : None
 RETURNS     : int
 		       Program successful execution without errors
===========================================================================
*/

int main () {

    int operation = 0;

    while(operation != 4) {
        printf("=====================================================\n");

        printf("Operation Menu: \n");
        printf("1. Power Problem Solver\n");
        printf("2. Factorial Problem Solver\n");
        printf("3. Finding the Roots of quadratic equations\n");
        printf("4. Exit\n");
        printf("Choose an operation: ");
        
        if(scanf("%d", &operation) != 1) {
            // If input is not a valid integer
            printf("Invalid input! Please enter a number.\n");

            // Clear the invalid input from buffer
            while(getchar() == '\n');  // This clears any extra characters left in input
            continue; // Ask for the input again
        }

        switch (operation) {
            case 1: {
                float base, power, result;
                printf("Enter the base: ");
                scanf("%f", &base);
                printf("Enter the exponent: ");
                scanf("%f", &power);

                result = powerProblemSolver(base, power);
                printf("The result is: %.2f\n", result);
                break;
            }
            case 2: {
                int num, result;
                printf("Enter number: ");
                scanf("%d", &num);

                result = factorialProblemSolver(num);
                printf("The result is: %d\n", result);
                break;
            }
            case 3: {
                float a, b, c;
                printf("Enter a: ");
                scanf("%f", &a);
                printf("Enter b: ");
                scanf("%f", &b);
                printf("Enter c: ");
                scanf("%f", &c);

                rootsProblemSolver(a, b, c);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default:
                printf("Invalid option! Please enter a number between 1 and 4.\n");
                break;
        }
    }   

    return 0;
}

/*
============================================================================
 FUNCTION    : powerProblemSolver
 DESCRIPTION : Computes exponential problems
 ARGUMENTS   : base, power
 RETURNS     : float
 		       result of exponential computaation
===========================================================================
*/
float powerProblemSolver(float base, float power) {
    int i;
    float result = 1;

    for (i = 0; i < power; i++) {
        result *= base;
    }

    return result;
}

/*
============================================================================
 FUNCTION    : factorialProblemSovler
 DESCRIPTION : Computes factorial problems
 ARGUMENTS   : x
 RETURNS     : int 
 		       result of factorial computaation
===========================================================================
*/
int factorialProblemSolver (int x) {
    int result = 1;
    int i;
    for(i = 1; i <= x; i++) {
        result *= i;
    }
    return result;
}

/*
============================================================================
 FUNCTION    : rootsProblemSovler
 DESCRIPTION : Computes factorial problems
 ARGUMENTS   : a, b, c
 RETURNS     : void 
 		       result of roots computaation
===========================================================================
*/

void rootsProblemSolver(float a, float b, float c) {
    float discriminant;
    float root1, root2;

    if (a == 0 && b == 0) {
        printf("There is no solution.\n");
    } else if (a == 0) {
        root1 = -c/b;
        printf("There is only one root: %.2f\n", root1);
    } else {
        discriminant = (b*b) - (4*a*c);

        if (discriminant < 0) {
            printf("There are no real roots.\n");
        } else {
            root1 = (-b + sqrt(discriminant)) / (2*a);
            root2 = (-b - sqrt(discriminant)) / (2*a);

            printf("The two roots are %.2f and %.2f.\n", root1, root2);
        }
    }
}