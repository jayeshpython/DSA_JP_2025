
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    int no;
    char name[20];
    struct Stack* next;
}stk;

stk* push(stk*);
stk* pop(stk*);
void displayStack(stk*);
void freeStack(stk*);

int main(){

    stk* top = NULL;
    int ch;

    while(1){
        printf("\n\t**********************************");
        printf("\n\t1. PUSH");
        printf("\n\t2. POP");
        printf("\n\t3. PRINT");
        printf("\n\t4. EXIT");
        printf("\n\tEnter the choice: ");
        scanf("%d", &ch);

        switch(ch){

            case 1:
            top = push(top);
            break;

            case 2:
            top = pop(top);
            break;

            case 3:
            displayStack(top);
            break;

            case 4:
            freeStack(top);
            break;

            default:
            printf("\n\tInvalid choice");
        }
    }
    return 0;
}

stk* push(stk* top){

    stk* newNode = (stk*)malloc(sizeof(stk));

    if(!newNode){
        printf("\n\tMemory allocation failed");
        return top;
    }
    else{
        printf("\n\tEnter number and name: ");
        scanf("%d %s", &newNode->no, newNode->name);

        newNode->next = top;
        return newNode;
    }
}

stk* pop(stk* top){

    if(!top){
        printf("\n\tStack is empty!");
        return NULL;
    }
    else{
        stk* p = top->next;
        printf("\n\t%d %s is popped from stack", top->no, top->name);
        free(top);
        return p;
    }
}

void displayStack(stk* top){
    if(!top){
        printf("\n\tStack is empty");
    }
    printf("\n\tStack element: ");
    for( ; top != NULL; top = top->next){
        printf("\n\tNumber = %d, Name = %s", top->no, top->name);
    }
}

void freeStack(stk* p){

    while(p){
        stk* temp = p;
        temp = temp->next;
        free(temp);
    }
    printf("\n\tMemory freed successfully");
}