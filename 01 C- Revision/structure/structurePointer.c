



#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[20];
    int rollNo;
    float marks;
}stud;

void accept(stud* ptr);
void display(stud* ptr);

int main(){

    stud s1;
    stud *ptr = &s1;
    accept(ptr);
    display(ptr);
    return 0;
}

void accept(stud *ptr){
    printf("\nEnter name: ");
    scanf("%s", ptr->name);
    printf("\nEnter roll no: ");
    scanf("%d", &ptr->rollNo);
    printf("\nEnter marks: ");
    scanf("%f", &ptr->marks);
}
void display(stud* ptr) {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", ptr->name);
    printf("Roll no: %d\n", ptr->rollNo);
    printf("Marks: %.2f\n", ptr->marks);
}
