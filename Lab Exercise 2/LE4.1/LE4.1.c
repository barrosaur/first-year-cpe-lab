#include <stdio.h>

int main() {

    char letter;

    printf("Enter letter: ");
    scanf("%c", &letter);

    if (letter == 'A' || letter == 'a' ||
        letter == 'E' || letter == 'e' ||
        letter == 'I' || letter == 'i' ||
        letter == 'O' || letter == 'o' ||
        letter == 'U' || letter == 'u'
        ) {
        printf("VOWEL!\n");
    } else if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <='Z')) {
        printf("CONSONANT!\n");
    } else {
        printf("INVALID INPUT!");
    }

    return 0;
}