
/*
write a C program to read and print the student details using structure and Dynamic Memory Allocation.
  - create a structure with student details and print the inputted details. 
  - Memory to store and print structure will be allocated at run time by using malloc() and released by free().
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char name[30];
    int rollNo;
    float marks;
} stud;

void accept(stud* ptr, int size);
void display(stud* ptr, int size);

int main() {
    int size = 5;
    stud* ptr = (stud*)malloc(sizeof(stud) * size);
    accept(ptr, size);
    display(ptr, size);

    free(ptr); 
    return 0;
}

void accept(stud* ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter name: ");
        scanf(" %[^\n]", ptr[i].name);
        printf("Enter roll no: ");
        scanf("%d", &ptr[i].rollNo);
        printf("Enter marks: ");
        scanf("%f", &ptr[i].marks);
    }
}

void display(stud* ptr, int size) {
    for (int i = 0; i < size; i++) {
        printf("\nStudent Details:");
        printf("\nName: %s", ptr[i].name);
        printf("\nRoll no: %d", ptr[i].rollNo);
        printf("\nMarks: %.2f\n", ptr[i].marks);
    }
}
