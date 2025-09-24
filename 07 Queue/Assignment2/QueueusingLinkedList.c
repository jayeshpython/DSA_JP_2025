
//write a c program to Create a queue and perform enqueue and dequeue operations(using Linked List) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue{
    int no;
    char name[20];
    struct Queue* next;
}que;

int isEmpty(que*);
que* enqueue(que*);
que* dequeue(que*, que**);
void display( que*);

int main(){
    que* front = NULL;
    que* rear = NULL;
    int ch;

    while(1){
        printf("\n\t***********************");
        printf("\n\tQueue Using Linked List");
        printf("\n\t1. Enqueue");
        printf("\n\t2. Dequeue");
        printf("\n\t3. Display");
        printf("\n\t4. Check If Empty");
        printf("\n\t5. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
            rear = enqueue(rear);
            if(front == NULL)       // if queue is empty, set front
            front = rear;
            break;

            case 2:
            rear = dequeue(rear, &front);
            break;

            case 3:
            display(front);
            break;

            case 4:
            if(isEmpty(front))
            printf("\n\tQueue is empty");
            else
            printf("\n\tQueue is not empty");
            break;

            case 5:
            printf("\n\tExiting.....");
            exit(0);

            default:
            printf("\n\tInvalid choice!");
        }
    }
    return 0;
}

int isEmpty(que* front){
    return front == NULL;
}

que* enqueue(que* rear){

    que* newNode = (que*)malloc(sizeof(que));
    printf("\n\tEnter number and name: ");
    scanf("%d %s", &newNode->no, newNode->name);

    newNode->next = NULL;
    
    if(rear != NULL){
        rear->next = newNode;
    }
    return newNode;
}

que* dequeue(que* rear, que** front){

    if(isEmpty(*front)){
        printf("\n\tQueue is empty");
        return rear;
    }
        que* temp = *front;
        printf("\n\t%d %s id dequeued", temp->no, temp->name);
        
        *front = (*front)->next;

        if(*front == NULL)
        rear = NULL;            // If queue is empty, update rear

        free(temp);
        return rear;
    }


void display(que* front){

    if(isEmpty(front)){
        printf("\n\tQueue is empty!");
        return;
    }
    que* temp = front;
    printf("\n\tQueue elements: ");
    while(temp != NULL){
        printf("\n\t%d %s", temp->no, temp->name);
        temp = temp->next;
    }
}