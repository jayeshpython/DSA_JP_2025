
//Write a C program to implement a Deque using a Circular Doubly Linked List.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dequeue{
    int no;
    char name[20];
    struct Dequeue* next;
    struct Dequeue* prev;
}dq;

dq* insertFront(dq* front, dq** rear);
dq* insertRear(dq* front, dq** rear);
dq* deleteFront(dq* front, dq** rear);
dq* deleteRear(dq* front, dq** rear);
void getFront(dq* front);
void getRear(dq* rear);
void display(dq* getFront);


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
            front = insertFront(front, &rear);
            break;

            case 2:
            front = insertRear(front, &rear);
            break;

            case 3:
            front = deleteFront(front, &rear);
            break;

            case 4:
            front = deleteRear(front, &rear);
            break;

            case 5:
            display(front);
            break;

            case 6:
            getFront(front);
            break;

            case 7:
            getRear(rear);
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

dq* insertFront(dq* front, dq** rear){

    dq* newNode = (dq*)malloc(sizeof(dq));
    if (!newNode) {
        printf("\n\tMemory allocation failed.");
        return front;
    }

    printf("\n\tEnter number and name: ");
    scanf("%d %s", &newNode->no, newNode->name);
    newNode->next = NULL;
    newNode->prev = NULL;

    if(front == NULL){
        front = *rear = newNode;
        front->next = front->prev = front;
    }
    else{
        newNode->next = front;
        newNode->prev = *rear;
        front->prev = newNode;
        (*rear)->next = newNode;
        front = newNode;
    }
    return front;
}

dq* insertRear(dq* front, dq** rear){

    dq* newNode = (dq*)malloc(sizeof(dq));
    if (!newNode) {
        printf("\n\tMemory allocation failed.");
        return front;
    }

    printf("\n\tEnter number and name: ");
    scanf("%d %s", &newNode->no, newNode->name);
    newNode->next = NULL;
    newNode->prev = NULL;

    if(front == NULL){
        front = *rear = newNode;
        front->next = front->next = NULL;
    }
    else{
        newNode->prev = *rear;
        newNode->next = front;
        (*rear)->next = newNode;
        front->prev = newNode;
        *rear = newNode;
    }
    return front;
}

dq* deleteFront(dq* front, dq** rear){

    if(!front){
        printf("\n\tDequeue is empty.");
        return NULL;
    }

    if(front == *rear){
        printf("\n\tDeleted node: %d %s", front->no, front->name);
        free(front);
        front = *rear = NULL;
    }
    else{
        dq* temp = front;
        front = front->next;
        front->prev = *rear;
        (*rear)->next = front;
        printf("\n\tDeleted node: %d %s", temp->no, temp->name);
        free(temp);
    }
    return front;
}

dq* deleteRear(dq* front, dq** rear){

    if(!front){
        printf("\n\tDequeue is empty");
        return NULL;
    }
    if(front == *rear){
        printf("\n\tDeleted node: %d %s", (*rear)->no, (*rear)->name);
        free(*rear);
        front = *rear = NULL;
    }
    else{
        dq* temp = *rear;
        *rear = (*rear)->prev;
        (*rear)->next = front;
        front->prev = *rear;
        printf("\n\tDeleted: %d %s", temp->no, temp->name);
        free(temp);
    }
    return front;
}

void getFront(dq* front){

    if (!front) {
        printf("\n\tDeque is empty.");
    } else {
        printf("\n\tFront element: %d %s", front->no, front->name);
    }
}

void getRear(dq* rear){

    if (!rear) {
        printf("\n\tDeque is empty.");
    } else {
        printf("\n\tRear element: %d %s", rear->no, rear->name);
    }
}

void display(dq* front){

    if (!front) {
        printf("\n\tDeque is empty.");
        return;
    }

    dq* temp = front;
    printf("\n\tDeque: ");
    do {
        printf("[%d %s] ", temp->no, temp->name);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}