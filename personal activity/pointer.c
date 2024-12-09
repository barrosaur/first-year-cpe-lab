#include <stdio.h>

int main() {
    int age = 21;
    int *ptr = &age;

    printf("*ptr: %d\n", *ptr);
    printf("ptr: %d\n", ptr);

    return 0;
}