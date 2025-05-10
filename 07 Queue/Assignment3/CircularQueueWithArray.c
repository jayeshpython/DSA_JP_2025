

#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct Queue{
    int arr[MAX];
    int front, rear;
}CircularQueue;

void insert(CircularQueue* que);
void delete(CircularQueue* que);
int isFull(CircularQueue* que);
int isEmpty(CircularQueue* que);
void display(CircularQueue* que);

int main(){
    CircularQueue que;
    int ch;
    que.front = que.rear = -1;

    while(1){
        printf("\n\n\t*************************");
        printf("\n\tCircular Queue with Array");
        printf("\n\t1. Enqueue");
        printf("\n\t2. Dequeue");
        printf("\n\t3. Display");
        printf("\n\t4. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
            insert(&que);
            break;

            case 2:
            delete(&que);
            break;

            case 3:
            display(&que);
            break;

            case 4:
            exit(0);

            default:
            printf("\n\tInvalid choice");
        }
    }
    return 0;
}

int isFull(CircularQueue* que){
    return ((que->rear+1)% MAX == que->front);
}

int isEmpty(CircularQueue* que){
    return (que->front == -1);
}

void insert(CircularQueue* que){

    if(isFull(que)){
        printf("\n\tQueue is full.");
        return;
    }

    int num;
    printf("\n\tEnter number: ");
    scanf("%d", &num);

    if(isEmpty(que)){
        que->front = que->rear = 0;
    }
    else{
        que->rear = (que->rear + 1)% MAX;
    }
    que->arr[que->rear] = num;
    printf("\tInserted successfully");
}

void delete(CircularQueue* que){

    if(isEmpty(que)){
        printf("\n\tQueue is empty");
        return;
    }

    printf("\n\tDeleted element: %d", que->arr[que->front]);

    if(que->front == que->rear){
        que->front = que->rear = -1;
    }
    else{
        que->front = (que->front + 1) % MAX;
    }
}

void display(CircularQueue* que){

    if(isEmpty(que)){
        printf("\n\tQueue is empty");
        return;
    }

    printf("\n\tQueue elements: ");

    int i = que->front;
    while(1){
        printf("%d ", que->arr[i]);

        if(i == que->rear)
        break;

        i = (i + 1) % MAX;
    }
}