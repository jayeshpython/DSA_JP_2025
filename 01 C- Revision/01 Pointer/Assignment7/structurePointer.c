

#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[20];
    int rollNo;
    char div;
    int std;
}student;

void accept(student*);
void display(student*);

int main(){

    student* stud = (student*)malloc(sizeof(student));
    accept(stud);
    display(stud);
    free(stud);
    return 0;
}

void accept(student* stud){
    printf("\n\tEnter name: ");
    scanf("%s", stud->name);
    printf("\n\tEnter roll no: ");
    scanf("%d", &stud->rollNo);
    printf("\n\tEnter division: ");
    scanf(" %c", &stud->div);
    printf("\n\tEnter standard: ");
    scanf("%d", &stud->std);
}

void display(student *stud) {
    printf("\n--- Student Details ---\n");
    printf("Name: %s\n", stud->name);
    printf("Roll No: %d\n", stud->rollNo);
    printf("Division: %c\n", stud->div);
    printf("Standard: %d\n", stud->std);
}