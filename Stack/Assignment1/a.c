

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  

int stack[MAX];
int top = -1; 

void push();
void pop();
void display();

int main() {

    push();
    display();
    pop();
    display();
    return 0;
}

void push() {
    if (top == MAX - 1) {  
        printf("\nStack overflow! Cannot push more elements.");
        return;
    }

    int value;
    printf("\nEnter value to push: ");
    scanf("%d", &value);

    stack[++top] = value;  
    printf("%d pushed to the stack.", value);
}

void pop() {
    if (top == -1) {  
        printf("\nStack underflow! No elements to pop.");
        return;
    }
    printf("\n%d popped from the stack.", stack[top--]);  
}

void display() {
    if (top == -1) {  
        printf("\nStack is empty.");
        return;
    }

    printf("\nStack elements:");
    for (int i = top; i >= 0; i--) {
        printf("\n%d", stack[i]);
    }
}

