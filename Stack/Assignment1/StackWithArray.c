
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int stack[MAX], top = -1;

void push();
void pop();
int isEmpty();
int isFull();
void peek();
void display();

int main(){

    int choice;

    while(1){
        printf("\n\t**************");
        printf("\n\tStack using array");
        printf("\n\t1 .PUSH");
        printf("\n\t2 .POP");
        printf("\n\t3 .PEEK");
        printf("\n\t4 .IsEMPTY");
        printf("\n\t5 .IsFULL");
        printf("\n\t6 .DISPLAY");
        printf("\n\t7 .EXIT");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            peek();
            break;

            case 4:
            printf(isEmpty() ?"\n\tStack is empty" : "\n\tStack is not empty");
            break;

            case 5:
            printf(isFull() ?"\n\tStack is full" : "\n\tStack is not full");
            break;

            case 6:
            display();
            break;

            case 7:
            exit(0);
            break;

            default:
            printf("\n\tInvalid choice");
        }
    }
}

void push(){

    if(isFull()){
        printf("\n\tStack Overflow! cannot push");
        return;
    }

    int value;
    printf("\n\tEnter the value: ");
    scanf("%d", &value);

    stack[++top] = value;
    printf("\n\tPushed %d to stack", value);
}

void pop(){

    if(isEmpty()){
        printf("\n\tStack Underflow! no elements to pop");
        return;
    }
    printf("\n\tPopped from stack", stack[top]);
    --top;
}

void peek(){

    if(isEmpty()){
        printf("\n\tStack is Empty! No top element");
        return;
    }
    printf("\n\tTop element is: %d", stack[top]);
    stack[top];
}

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == MAX - 1;
}

void display(){

    if(isEmpty()){
        printf("\n\tStack is empty");
    }
    printf("\n\tStack elements: ");
    for(int i = top; i >= 0; i--){
        printf("\n\t%d", stack[i]);
    }
}
