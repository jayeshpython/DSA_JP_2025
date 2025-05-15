

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Dequeue{
    int arr[MAX];
    int front;
    int rear;
};

typedef struct Dequeue DQ;

void initDequeue(DQ* dq){
    dq->front = dq->rear = -1;
}

int isFull(DQ* dq){
    return ( (dq->front == 0 && dq->rear == MAX-1) || (dq->front == dq->rear+1));
}

int isEmpty(DQ* dq){
    return (dq->front == -1);
}

void insertFront(DQ* dq, int value){

    if(isFull(dq)){
        printf("\n\tQueue is full.");
        return;
    }

    if(isEmpty(dq)){
        dq->front = dq->rear = 0;
    }
    else if(dq->front == 0){
        dq->front = MAX-1;
    }else{
        dq->front--;
    }

    dq->arr[dq->front] = value;
    printf("\n\tInsert %d at front: ", value);
}

void insertRear(DQ* dq, int value){

    if(isFull(dq)){
        printf("\n\tDequeue is full.");
        return;
    }

    if(isEmpty(dq)){
        dq->front = dq->rear = 0;
    }
    else if(dq->rear == MAX - 1){
        dq->rear = 0;
    }else{
        dq->rear++;
    }

    dq->arr[dq->rear] = value;
    printf("\n\tInserted %d at rear: ", value);
}

void deleteFront(DQ* dq){

    if(isEmpty(dq)){
        printf("\n\tDequeue is empty.");
        return;
    }
    printf("Deleted %d from front: ", dq->arr[dq->front]);

    if(dq->front == MAX - 1){
        dq->front = 0;
    }
    else if(dq->front == dq->rear){
        dq->front = dq->rear = -1;
    }else{
        dq->front++;
    }
}

void deleteRear(DQ* dq){

     if(isEmpty(dq)){
        printf("\n\tDequeue is empty.");
        return;
    }
    printf("Deleted %d from rear: ", dq->arr[dq->rear]);
    
    if(dq->front == dq->rear){
        dq->front = dq->rear = -1;
    }
    else if(dq->rear == 0){
        dq->rear = MAX - 1;
    }else{
        dq->rear--;
    }
}

int getFront(DQ* dq){

    if (isEmpty(dq)) {
        printf("\n\tQueue is empty.");
        return -1;
    }
    return dq->arr[dq->front];
}

int getRear(DQ* dq){

    if (isEmpty(dq)) {
        printf("\n\tQueue is empty.");
        return -1;
    }
    return dq->arr[dq->rear];
}

void display(DQ* dq){

     if (isEmpty(dq)) {
        printf("\n\tQueue is empty.");
        return;
    }

    printf("\n\tDequeue Elements: ");
    int i = dq->front;

    while(1){
        printf("%d ", dq->arr[i]);

        if(i == dq->rear)
        break;

        i = (i+1) % MAX;
    }
    printf("\n");
}

int main(){

    DQ dq;
    initDequeue(&dq);
    int choice, value;

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
            printf("\n\tEnter value to insert at front: ");
            scanf("%d", &value);
            insertFront(&dq, value);
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