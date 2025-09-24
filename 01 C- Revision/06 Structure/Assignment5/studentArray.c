
/*
Create a structure "Students" with below member variables:
	- Name of student,
    - Roll no. Of Student,
    - array of 5 Subject marks,
	- Total Percentage 
    
- Calculate the Percentage for "N" number of students,
- Display all details for all students,
- Display the details of topper.
(use array of structure)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[20];
    int rollNo;
    int marks[5];
    float percentage;
}stud;

void accept(stud* ptr, int size);
void calPercentage(stud* ptr, int size);
void display(stud* ptr, int size);
void topperStudent(stud* ptr, int size);

int main(){

    int size = 5;
    stud* ptr = (stud*)malloc(sizeof(stud)* size);

    accept(ptr, size);
    calPercentage(ptr, size);
    display(ptr, size);
    topperStudent(ptr, size);
    free(ptr);
    return 0;
}
    
void accept(stud* ptr, int size){
    
    for(int i=0; i<size; i++){
        printf("\nEnter name: ");
        scanf("%s", ptr[i].name);
        printf("Enter roll no: ");
        scanf("%d", &ptr[i].rollNo);
        
        printf("Enter marks of 5 subjects:\n");
        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &ptr[i].marks[j]);
        }
    }
}

void calPercentage(stud* ptr, int size){
    
    for(int j=0; j<size; j++){
        int sum=0;

    for(int i=0; i<5; i++){
        sum += ptr[j].marks[i];
    }
    ptr[j].percentage = sum/5;
    }
}

void display(stud* ptr, int size){
    printf("\n********************");
    for(int i=0; i<size; i++){
    printf("\nStudent details");
    printf("\nName: %s", ptr[i].name);
    printf("\nRoll no: %d", ptr[i].rollNo);
    printf("\nPercentage: %f", ptr[i].percentage);
    }
}

void topperStudent(stud* ptr, int size) {
    int topperIndex = 0;
    float max = ptr[0].percentage;

    for (int i = 1; i < size; i++) {
        if (ptr[i].percentage > max) {
            max = ptr[i].percentage;
            topperIndex = i;
        }
    }

    printf("\n********************");
    printf("\nTopper Student:");
    printf("\nName: %s", ptr[topperIndex].name);
    printf("\nRoll No: %d", ptr[topperIndex].rollNo);
    printf("\nPercentage: %.2f%%\n", ptr[topperIndex].percentage);
}


