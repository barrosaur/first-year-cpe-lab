//display yes if Y is pressed or no when N is pressed

#include <stdio.h>
#include <stdlib.h>

int main () {
    char key;

    printf("Y/N?\n");
    key = getche();

    if (key == 'Y') {
        printf("\nYes");
    } else if (key == 'N') {
        printf("\nNo");
    } else {
        printf("\nInvalid key\n");
    }

    return 0;
}