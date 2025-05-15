

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dequeue{
    int no;
    char name[20];
    struct Dequeue* next;
    struct Dequeue* prev;
}dq;

dq* insertFront(dq*, dq*);
dq* insertRear(dq*, dq*);
dq* deleteFront(dq*, dq*);
dq* deleteRear(dq*, dq*);
dq* getFront(dq*);
dq* getRear(dq*);
void display(dq*);


int main(){

    dq* front = NULL;
    dq* rear = NULL;
    int choice;

    while(1){
        printf("\n\t********Circular Dequeue Menu********");
        printf("\n\t1. Insert at Front.");
        printf("\n\t2. Insert at Rear.");
        printf("\n\t3. Delete from Front.");
        printf("\n\t4. Delete from Rear.");
        printf("\n\t5. Display Dequeue.");
        printf("\n\t6. Get Front Element.");
        printf("\n\t7. Get Rear Element.");
        printf("\n\t8. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            front = insertFront(&dq, value);
            break;

            case 2:
            printf("\n\tEnter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(&dq, value);
            break;

            case 3:
            deleteFront(&dq);
            break;

            case 4:
            deleteRear(&dq);
            break;

            case 5:
            display(&dq);
            break;

            case 6:
            value = getFront(&dq);
            if(value != -1)
            printf("\n\tFront element: %d", value);
            break;

            case 7:
            value = getRear(&dq);
            if(value != -1)
            printf("\n\tRear element: %d", value);
            break;

            case 8:
            printf("\n\tExiting....");
            exit(0);

            default:
            printf("\n\tInvalid choce");
        }
    }
    return 0;
}