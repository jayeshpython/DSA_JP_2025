#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Priority {
    int no;
    char name[20];
    struct Priority* next;
    struct Priority* prev;
}pri;

pri* insert(pri** front, pri** rear);
pri* delete(pri** front, pri* rear);
int isEmpty(pri* front);
void display(pri* front);

int main(){

    pri* front = NULL;
    pri* rear = NULL;
    int ch;

    while (1){
        printf("\n\t*************************");
        printf("\n\tPriority Queue using Doubly Linked List");
        printf("\n\t1. Insertion");
        printf("\n\t2. Deletion");
        printf("\n\t3. Check if empty");
        printf("\n\t4. Display");
        printf("\n\t5. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch (ch){

            case 1:
                front = insert(&front, &rear);
                break;

            case 2:
                rear = delete(&front, rear);
                break;

            case 3:
                if (isEmpty(front)) {
                    printf("\n\tQueue is empty.");
                } else {
                    printf("\n\tQueue is not empty.");
                }
                break;

            case 4:
                display(front);
                break;

            case 5:
                exit(0);

            default:
                printf("\n\tInvalid choice");
        }
    }
    return 0;
}

int isEmpty(pri* front){
    return front == NULL;
}

pri* insert(pri** front, pri** rear){

    pri* newNode = (pri*)malloc(sizeof(pri));
    if (!newNode) {
        printf("\n\tMemory allocation failed.");
        return *front;
    }

    printf("\n\tEnter number and name: ");
    scanf("%d %s", &newNode->no, newNode->name);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*front == NULL) {
        *front = *rear = newNode;
        return *rear;
    }

    if (newNode->no < (*front)->no) {
        newNode->next = *front;
        (*front)->prev = newNode;
        *front = newNode;
        return *front;
    }

    pri* temp = *rear;
    while (temp != NULL && temp->no > newNode->no) {
        temp = temp->prev;
    }

    if (temp == NULL){
        newNode->next = *front;
        (*front)->prev = newNode;
        *front = newNode;
    } 
    else if (temp->next == NULL) {
        temp->next = newNode;
        newNode->prev = temp;
        *rear = newNode;
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    return *front;
}

pri* delete(pri** front, pri* rear){

    if (isEmpty(*front)) {
        printf("\n\tQueue is empty.");
        return rear;
    }

    pri* temp = *front;
    printf("\nDeleted node: %d %s", temp->no, temp->name);
    *front = (*front)->next;

    if (*front != NULL) {
        (*front)->prev = NULL;
    }else {
        rear = NULL;
    }

    free(temp);
    return rear;
}

void display(pri* front){

    if (front == NULL) {
        printf("\n\tQueue is empty.");
        return;
    }

    pri* temp = front;
    printf("\n\tQueue elements: \n");
    while (temp != NULL) {
        printf("\t%d %s\n", temp->no, temp->name);
        temp = temp->next;
    }
}
