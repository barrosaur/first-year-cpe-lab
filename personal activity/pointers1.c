#include <stdio.h>

void printAge(int *pointerAge);

int main() {
    int age = 21;
    int *pointerAge = &age;

    //* => value at address -> so it helps

    // printf("Address of age: %p\n", &age); //ampersand of age
    // printf("Address of pointerAge: %p\n", pointerAge);

    // printf("Value of age: %d\n", age); //value of age
    // printf("Value of pointerAge: %d\n", *pointerAge);

    // printf("Size of age: %d bytes\n", sizeof(age));
    // printf("Size of pointerAge: %d bytes\n", sizeof(pointerAge));

    printAge(pointerAge);

    return 0;
}

void printAge(int *pointerAge) {
    printf("Age %d\n", *pointerAge);
}