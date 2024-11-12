#include <stdio.h>

int main() {
    int num[2][3];

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Enter number #%d: ", j+1);
            scanf("%d", &num[i][j]);
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }

    return 0;
}