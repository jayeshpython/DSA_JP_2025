
/*
Write a c program which demonstrate a nested structure 
	- define a structure employee inside a structure person.
    - structure person data: 
                        Name, Age, Date of birth, blood group.
    - structure employee data:
                        Company name, Emp id, salary, years of experiance.
						
	- create objects of structure and display the all details of a person.
*/

#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char companyName[30];
    int empId;
    double salary;
    int experience;
} Employee;

typedef struct {
    char name[30];
    int age;
    Date dob;  
    char bloodGroup[5];
    Employee emp; 
} Person;

int main() {
    Person p;

    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter Date of Birth (DD MM YYYY): ");
    scanf("%d %d %d", &p.dob.day, &p.dob.month, &p.dob.year);

    printf("Enter Blood Group: ");
    scanf("%s", p.bloodGroup);

    printf("Enter Company Name: ");
    scanf(" %[^\n]", p.emp.companyName);

    printf("Enter Employee ID: ");
    scanf("%d", &p.emp.empId);

    printf("Enter Salary: ");
    scanf("%lf", &p.emp.salary);

    printf("Enter Years of Experience: ");
    scanf("%d", &p.emp.experience);

   
    printf("\n********** Person Details **********\n");
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Date of Birth: %02d-%02d-%d\n", p.dob.day, p.dob.month, p.dob.year);
    printf("Blood Group: %s\n", p.bloodGroup);

    printf("\n********** Employee Details **********\n");
    printf("Company Name: %s\n", p.emp.companyName);
    printf("Employee ID: %d\n", p.emp.empId);
    printf("Salary: %.2lf\n", p.emp.salary);
    printf("Years of Experience: %d\n", p.emp.experience);

    return 0;
}
