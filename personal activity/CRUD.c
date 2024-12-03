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
void addStudent(STUDENT stud[], int *studentCount, int maxStudent);
void displayList(STUDENT stud[], int studentCount);

int main() {
    STUDENT student[10];
    int choice = 0;
    // char c;
    bool condition = true;
    char mainMenuOptions[5][50] = {"Add a student.", "Update student information.", "Delete student information.", "Display Student Information.", "Exit."};
    int menuCount = 5, studentSize = 10, studentCount = 0;

    while(condition) {
        printf("=============================================================================================\n");
        printf("Welcome to the Portal!\n");

        displayMenu(mainMenuOptions, menuCount);
        
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(student, &studentCount, studentSize);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                displayList(student, studentCount);
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

void addStudent(STUDENT stud[], int *studentCount, int maxStudent) {
    if(*studentCount >= maxStudent) {
        printf("Cannot add more students. Maximum threshold reached.\n");
        return;
    }

    STUDENT *newStudent = &stud[*studentCount];

    printf("Enter student name: ");
    getchar();
    gets(newStudent->name);

    printf("Enter course: ");
    gets(newStudent->course);

    printf("Enter ID: ");
    scanf("%d", &newStudent->idNumber);

    printf("Enter year: ");
    scanf("%d", &newStudent->year);

    (*studentCount)++;
}

void displayList(STUDENT stud[], int studentCount) {
    int i;

    if(studentCount == 0) {
        printf("No students are available for display.\n");
        return;
    }

    printf("\n-----------------------------------------Student List-----------------------------------------\n");
    for(i = 0; i < studentCount; i++) {
        printf("[%d]\t%s - %s\t ID: %d\t Year: %d\n", i+1, stud[i].name, stud[i].course, stud[i].idNumber, stud[i].year);
    }
}