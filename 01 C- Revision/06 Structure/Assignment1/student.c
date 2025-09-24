
/*
write a C program to create, declare and initialize structure.
    - define a structure "student", which includes the details of students,
    - declare an object of the structure and initialize the structure members.
*/

#include <stdio.h>

typedef struct Student{
	char name[30];
	int rollNo;
	int age;
	float marks;
	char grade;
}Student;

int main(){
	Student stud;
	
	printf("Enter name: ");
	scanf(" %[^\n]", stud.name);
	printf("Enter roll no: ");
	scanf("%d", &stud.rollNo);
	printf("Enter age: ");
	scanf("%d", &stud.age);
	printf("Enter marks: ");
	scanf("%f", &stud.marks);
	printf("Enter grade: ");
	scanf(" %c", &stud.grade);
	
	printf("\n************************");
	printf("\nName: %s", stud.name);
	printf("\nRoll no: %d", stud.rollNo);
	printf("\nAge: %d", stud.age);
	printf("\nMarks: %f", stud.marks);
	printf("\nGrade: %c", stud.grade);
	
	return 0;
}


