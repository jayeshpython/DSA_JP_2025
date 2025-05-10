

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct{
    int que[MAX];
    int front, rear;
} Priority;

void insert(Priority* pq, int value);
int delete(Priority* pq);
void peek(Priority* pq);
void display(Priority* pq);

int main(){
    Priority pq;
    int value, ch;

    pq.front = pq.rear = -1;

    while(1){
        printf("\n\t*************************");
        printf("\n\tPriority Queue using FIFO");
        printf("\n\t1. Insertion");
        printf("\n\t2. Deletion");
        printf("\n\t3. Peek");
        printf("\n\t4. Display");
        printf("\n\t5. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){

            case 1:
                printf("\tEnter value: ");
                scanf("%d", &value);
                insert(&pq, value);
                break;

            case 2:
                value = delete(&pq);
                if(value != -1){
                    printf("\n\tDeleted minimum element: %d", value);
                }
                break;

            case 3:
                peek(&pq);
                break;

            case 4:
                display(&pq);
                break;

            case 5:
                exit(0);

            default:
                printf("\n\tInvalid choice");
        }
    }
    return 0;
}

void insert(Priority* pq, int value){

    if(pq->rear == MAX - 1){
        printf("\n\tQueue is full.");
        return;
    }

    if(pq->front == -1){
        pq->front = pq->rear = 0;
        pq->que[pq->rear] = value;
        return;
    }

    int i = pq->rear;
    while(i >= pq->front && pq->que[i] > value){
        pq->que[i+1] = pq->que[i];
        i--;
    }
    pq->que[i+1] = value;
    pq->rear++;
}

int delete(Priority* pq){

    if(pq->front == -1){
        printf("\n\tQueue is empty.");
        return -1;
    }

    int min_value = pq->que[pq->front];

    for(int i = pq->front; i < pq->rear; i++){
        pq->que[i] = pq->que[i+1];
    }
    pq->rear--;

    if(pq->rear < pq->front){
        pq->front = pq->rear = -1;
    }

    return min_value;
}

void peek(Priority* pq){

    if(pq->front == -1){
        printf("\n\tQueue is empty.");
    } else {
        printf("\n\tMinimum value: %d", pq->que[pq->front]);
    }
}

void display(Priority* pq){
    
    if(pq->front == -1){
        printf("\n\tQueue is empty.");
    } else {
        printf("\n\tQueue elements: ");
        for(int i = pq->front; i <= pq->rear; i++){
            printf("%d ", pq->que[i]);
        }
        printf("\n");
    }
}
