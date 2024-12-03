#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

typedef struct student {
    char name[50];
    char course[50];
    int idNumber;
    int year;
} STUDENT;

void displayMenu(char mainMenuOptions[][50], int size);

int main() {
    STUDENT student;
    int choice = 0;
    // char c;
    bool condition = true;
    char mainMenuOptions[5][50] = {"Add a student.", "Update student information.", "Delete student information.", "Display Student Information.", "Exit."};
    int menuCount = 5;

    while(condition) {
        printf("Welcome to the Portal!\n");
        printf("=================================================================================\n");

        displayMenu(mainMenuOptions, menuCount);
        
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Exiting Program...\n");
                return 0;
        }
    }

    return 0;
}

void displayMenu(char mainMenuOptions[][50], int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("[%d] - %s\n", i+1, mainMenuOptions[i]);
    }

    return;
}