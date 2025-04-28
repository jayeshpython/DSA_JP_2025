

# include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

typedef struct Queue{
    int no;
    char name[20];
}que;

int enqueue(int, que*);
int dequeue(int, int, que*);
void display(int, int, que*);

int main(){
    que a[MAX];
    int front = 0, rear = -1;
    int ch;

    while(1){
        printf("\n\t*************************");
        printf("\n\tQueue with Array");
        printf("\n\t1. Enqueue");
        printf("\n\t2. Dequeue");
        printf("\n\t3. Display");
        printf("\n\t4. Exit");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
            rear = enqueue(rear, a);
            break;

            case 2:
            front = dequeue(front, rear, a);
            if(front == 0)      // reset rear if queue is empty
            rear == -1;
            break;

            case 3:
            display(front, rear, a);
            break;

            case 4:
            exit(0);

            default:
            printf("\n\tInvalid coice");
        }
    }
    return 0;
}

//Inserting elements in queue
int enqueue(int rear, que* a){
    if(rear == MAX - 1)
    printf("\n\tQueue is Full");

    else{
        rear++;
        printf("\n\n\tEnter n number and name: ");
        scanf("%d %s", &a[rear].no, a[rear].name);
    }
    return rear;
}

//Removing elements from queue
int dequeue(int front, int rear, que* a){

    if(rear == -1){
        printf("\n\tQueue is empty!");
    }
    else if(front == rear)    // if last element removed, reset front
    front = 0;

    else{
        printf("\n\t%d is deleted", a[front].no);
        front++;
    }
    return front;
}

//display function
void display(int front, int rear, que* a){

    if(rear == -1){
        printf("\n\tQueue is empty");
        return;
    }
    for(int i = front; i <=rear; i++){
        printf("\n\t%d %s", a[i].no, a[i].name);
    }
}

