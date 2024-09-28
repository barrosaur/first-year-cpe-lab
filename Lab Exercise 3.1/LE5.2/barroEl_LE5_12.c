#include <stdio.h>

#define CORRECT_PASSCODE 123456

int main() {
    int passcodePrompt;
    int attempt = 0;

    while (attempt < 3) {
        printf("Enter passcode: ");
        scanf("%d", &passcodePrompt);

        if (passcodePrompt == CORRECT_PASSCODE) {
            printf("ACCESS GRANTED!");
            return 0;
        } else {
            attempt++;
            if(attempt < 3) {
                printf("Invalid Password. Try Again.\n");
            }
        }
    }

    printf("ACCESS DENIED!");

    return 0;
}
