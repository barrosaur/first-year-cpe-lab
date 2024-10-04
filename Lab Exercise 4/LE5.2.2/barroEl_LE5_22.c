#include <stdio.h>

int main() {
    int i, j;
    int num;

    printf("Enter num: ");
    scanf("%d", &num);

    //for every row
    for(i = 1; i <= num; i++) {

        //kani siya spaces before numbers
        for(j = i; j < num; j++) {
            printf("  ");
        }

        //increase num --> 1 then 2 then 3 
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        //decreasing nums like the ones on the sides 
        for(j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }

        //next line
        printf("\n");

    }

    return 0;
}