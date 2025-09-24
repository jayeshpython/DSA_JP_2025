
//Write a C program to implement a Priority Queue using a Normal Array.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int value;
    int priority;
}Priority;

void insertValue(Priority*, int*, int, int);
void deleteValue(Priority*, int*);
void display(Priority*, int*);

int main(){
     
    Priority arr[MAX];
    int value,priority, ch;
    int size = 0;

    while(1){
        printf("\n\t*************************");
        printf("\n\tPriority Queue with Array");
        printf("\n\t1. Insertion");
        printf("\n\t2. Deletion");
        printf("\n\t3. Display");
        printf("\n\t4. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
            printf("\tEnter value: ");
            scanf("%d", &value);
            printf("\tEnter priority: ");
            scanf("%d", &priority);

            insertValue(arr, &size, value, priority);
            break;

            case 2:
            deleteValue(arr, &size);
            break;

            case 3:
            display(arr,&size);
            break;

            case 4:
            exit(0);

            default:
            printf("\n\tInvalid coice");
        }
    }
    return 0;
}

void insertValue(Priority arr[], int* size, int value, int priority){

    if(*size == MAX){
        printf("\n\tQueue is full.");
        return;
    }
    
    int i = *size - 1;
    while(i >= 0 && arr[i].priority > priority){
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1].value = value;
    arr[i+1].priority = priority;
    (*size)++;
}

void deleteValue(Priority arr[], int* size){

    if(*size == 0){
        printf("\n\tQueue is empty.");
        return;
    }

    printf("\n\tDeleted value and priority: %d %d", arr[0].value, arr[0].priority);

    for(int i = 1; i < *size; i++){
        arr[i-1] = arr[i];
    }
    (*size)--;
}

void display(Priority arr[], int* size){

    if(*size == 0){
        printf("\n\tQueue is empty.");
        return;
    }

    printf("\n\tPriority Queue Elements: ");
    for(int i = 0; i < *size; i++){
        printf("\n\tValue = %d, Priority = %d", arr[i].value, arr[i].priority);
    }
}