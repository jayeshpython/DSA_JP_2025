
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


int main(){

    int size = 5;
    stud* ptr = (stud*)malloc(sizeof(stud)* size);

    accept(ptr, size);
    calPercentage(ptr, size);
    display(ptr, size);
    

    free(ptr);
    return 0;
}
    
void accept(stud* ptr, int size){
    
    for(int i=0; i<size; i++){
        printf("\nEnter name: ");
        scanf("%s", ptr->name);
        printf("Enter roll no: ");
        scanf("%d", &ptr->rollNo);
        
        printf("Enter marks of 5 subjects:\n");
        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &ptr->marks[j]);
        }
        ptr++;
    }
}

void calPercentage(stud* ptr, int size){
    
    for(int j=0; j<size; j++){
        int sum=0;

    for(int i=0; i<5; i++){
        sum += ptr->marks[i];
    }
    ptr->percentage = sum/5;
    ptr++;
    }
}

void display(stud* ptr, int size){
    printf("\n********************");
    for(int i=0; i<size; i++){
    printf("\nStudent details");
    printf("\nName: %s", ptr->name);
    printf("\nRoll no: %d", ptr->rollNo);
    printf("\nPercentage: %f", ptr->percentage);
    ptr++;
}
}



