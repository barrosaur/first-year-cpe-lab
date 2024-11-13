#include <stdio.h>

#define PI 3.14

float calculateCircleArea(float r);

int main() {
    float radius;
    float result;

    printf("Enter radius: ");
    scanf("%f", &radius);

    result = calculateCircleArea(radius);
    printf("Circle area: %.2f\n", result);

    return 0;
}

float calculateCircleArea(float r) {
    return PI*(r*r);
}