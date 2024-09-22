#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float root1, root2;
    float discriminant;

    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);

    if (a == 0 && b == 0) {
        printf("There is no solution.");
    } else if (a == 0) {
        root1 = -c/b;
        printf("There is only one root: %.2f", root1);
    } else {
        discriminant = (b*b) - (4*a*c);

        if (discriminant < 0) {
            printf("There are no real roots.");
        } else {
            root1 = (-b + sqrt(discriminant)) / (2*a);
            root2 = (-b - sqrt(discriminant)) / (2*a);
            printf("The roots are %.2f and %.2f", root1, root2);
        }
    }

    return 0;
}