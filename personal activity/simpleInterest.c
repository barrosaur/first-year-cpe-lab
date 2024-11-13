#include <stdio.h>

double computeSimpleInterest(double rate, double principal, double time);

int main() {
    double rate, principal, time;
    double result;

    printf("Enter your rate: ");
    scanf("%lf", &rate);
    printf("Enter principal: ");
    scanf("%lf", &principal);
    printf("Enter time: ");
    scanf("%lf", &time);

    result = computeSimpleInterest(rate, principal, time);
    printf("Simple interest is: $%.2f\n", result);

    return 0;
}

double computeSimpleInterest(double rate, double principal, double time) {
    double interest = (rate / 100) * principal * time;
    return interest;
}
