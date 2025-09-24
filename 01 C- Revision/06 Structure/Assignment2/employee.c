
/*
write a C program to read and print an employee's detail using structure.
   - read and print the employee's details like name, employee id, salary etc using structure.
*/
#include <stdio.h>

typedef struct Employee {
    char name[20];
    int empId;
    double salary;
} Employee;

int main() {
    Employee emp;

    printf("Enter name: ");
    scanf("%s", emp.name);  
    printf("Enter ID: ");
    scanf("%d", &emp.empId);

    printf("Enter salary: ");
    scanf("%lf", &emp.salary); 

    printf("\n**************************\n");
    printf("Employee name: %s\n", emp.name);
    printf("Employee ID: %d\n", emp.empId);
    printf("Employee salary: %.2lf\n", emp.salary);  
    return 0;
}
