//Pascal's triangle
#include <stdio.h>

int main() {
    int height;

    printf("Enter height: ");
    scanf("%d", &height);

    int triangle[height][height]; //first bracket is row; second is column

    //i - gawas
    //j - sulod
    for(int gawas = 0; gawas < height; gawas++) {
        for(int sulod = 0; sulod <= gawas; sulod++) {
            if(sulod == 0 || sulod == gawas) {
                // ang value ni first ug last kada row is 1
                triangle[gawas][sulod] = 1;
            } else {
                triangle[gawas][sulod] = triangle[gawas - 1][sulod -1] + triangle[gawas -1][sulod];
            }
        }
    }

    //display
    for(int gawas = 0; gawas < height; gawas++) {
        for(int sulod1 = height - gawas; sulod1 > 0; sulod1--) {
            printf(" ");
        }

        for(int sulod2 = 0; sulod2 <= gawas; sulod2++) {
            printf("%d ", triangle[gawas][sulod2]);
        }

        printf("\n");
    }

    return 0;
}