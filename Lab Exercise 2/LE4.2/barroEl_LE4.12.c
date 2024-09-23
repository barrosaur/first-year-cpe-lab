/*
============================================================================
 FILE        : barroEl_LE4.12.c
 AUTHOR      : Ellaine Joyce Barro
 DESCRIPTION : Computed the root of a Quadratic Equation
 COPYRIGHT   : created
 REVISION HISTORY
 Date:               By: 	                Description:
 09/22/24            Ellaine Joyce Barro    Made the entire program
============================================================================
*/

#include <stdio.h>
#include <math.h>

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Gets constants from user and determines its roots
 ARGUMENTS   : None
 RETURNS     : int
 		       Program successful execution without errors
===========================================================================
*/

int main() {
    float a, b, c;
    float root1, root2;
    float discriminant;

    //GET constants a, b, c
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);

    //CHECK conditions
    if (a == 0 && b == 0) {
        //DISPLAY
        printf("There is no solution.");
    } else if (a == 0) {
        //COMPUTE root1
        root1 = -c/b;

        //DISPLAY root1
        printf("There is only one root: %.2f", root1);
    } else {
        //COMPUTE discriminant
        discriminant = (b*b) - (4*a*c);

        //CHECK condition with regards to discriminant
        if (discriminant < 0) {
            //DISPLAY no real roots
            printf("There are no real roots.");
        } else {
            //COMPUTE root1, root2
            root1 = (-b + sqrt(discriminant)) / (2*a);
            root2 = (-b - sqrt(discriminant)) / (2*a);

            //DISPLAY root1, root2
            printf("The roots are %.2f and %.2f", root1, root2);
        }
    }

    return 0;
}