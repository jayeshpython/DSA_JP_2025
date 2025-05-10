

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Queue{
    int no;
    char name[20];
    struct Queue* next;
}que;

que* insert(que*, que*);
que* delete(que**, que**);
int  isEmpty(que*);
void display(que*);

int main(){

    que* front = NULL;
    que* rear = NULL;
    int ch;

    while(1){
        printf("\n\n\t*************************");
        printf("\n\tCircular Queue with Linked List");
        printf("\n\t1. Enqueue");
        printf("\n\t2. Dequeue");
        printf("\n\t3. Display");
        printf("\n\t4. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
    
            case 1:
            rear = insert(front, rear);
            if(front == NULL)
            front = rear;
            break;

            case 2:
            rear = delete(&front, &rear);
            break;

            case 3:
            display(front);
            break;

            case 4:
            exit(0);

            default:
            printf("\n\tInvalid choice");
        }
    }
    return 0;
}

que* insert(que* front, que* rear){

    que* newNode = (que*)malloc(sizeof(que));
    if(!newNode){
        printf("\n\tMemory allocation failed.");
        return rear;
    }

    printf("\n\tEnter number and name: ");
    scanf("%d %s", &newNode->no, newNode->name);

    if(rear == NULL){
        front = rear = newNode;
        rear->next = front;
    } else{
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    return rear;
}

que* delete(que** front, que** rear){

    if(isEmpty(*front)){
        printf("\n\tQueue is empty.");
        return *rear;
    }
    que* temp = *front;

    if(*front == *rear){
        printf("\n\tDequeued element: %d %s", temp->no, temp->name);
        free(temp);
        *front = *rear = NULL;
    }
    else{
        printf("\n\tDequeued element: %d %s", temp->no, temp->name);
        *front = (*front)->next;
        (*rear)->next = *front;
        free(temp);
    }
    return *rear;
}

int isEmpty(que* front){
    return front == NULL;
}

void display(que* front){

    if (front == NULL) {
        printf("\n\tQueue is empty.");
        return;
    }

    que* temp = front;
    printf("\n\tQueue elements: \n");
    do {
        printf("\t%d %s\n", temp->no, temp->name);
        temp = temp->next;
    } while (temp != front);
}