#include <stdio.h>

int main() {
    int numOfStudents = 0;
    char studentName[10][20];
    int i, j;
    float studentGrade[10];
    float averageGrade = 0;

    printf("Enter number of Students: ");
    scanf("%d", &numOfStudents);
    getchar(); //when pressing enter after getting the no. of students, the enter is the person for #1

    for(i = 0; i < numOfStudents; i++) {
        printf("Enter name of student #%d: ", i+1);
        gets(studentName[i]);
        printf("Enter grade: ");
        scanf("%f", &studentGrade[i]);
        getchar(); 
    }

    printf("\n==============================================================================\n");

    for(i = 0; i < numOfStudents; i++) {
        averageGrade += studentGrade[i];
    }
    averageGrade /= numOfStudents;

    printf("Student information: \n");
    for(i = 0; i < numOfStudents; i++) {
        printf("Student name: %s\t\t\t\t |  Grade: %.2f\n", studentName[i], studentGrade[i]);
    }

    printf("\n------------------------------------------\n");
    printf("Average grade: \t\t%.2f\n", averageGrade);

    return 0;
}