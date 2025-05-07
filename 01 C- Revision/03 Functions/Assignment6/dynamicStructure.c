

#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char name[30];
    int rollNo;
    float marks;
} stud;

void accept(stud* ptr, int size);
void display(stud* ptr, int size);
void searchForParticularStudent(stud* ptr, int size);

int main() {
    int size = 3;
    stud* ptr = (stud*)malloc(sizeof(stud) * size);
    accept(ptr, size);
    display(ptr, size);
    searchForParticularStudent(ptr, size);

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

void searchForParticularStudent(stud* ptr, int size) {
    
    int roll;
    int found = 0;

    printf("\nEnter roll number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < size; i++) {
        if (ptr[i].rollNo == roll) {
            printf("\n--- Student Found ---");
            printf("\nName: %s", ptr[i].name);
            printf("\nRoll no: %d", ptr[i].rollNo);
            printf("\nMarks: %.2f\n", ptr[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with roll number %d not found.\n", roll);
    }
}