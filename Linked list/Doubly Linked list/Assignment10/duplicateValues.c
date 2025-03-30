

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNode{
    int no;
    char name[20];
    struct DNode* next;
    struct DNode* prev;
}DNode;

DNode* create(DNode*);
void display(DNode*);
void freeList(DNode*);
//void duplicateValues(DNode*);

int main(){

    DNode* start = NULL;
    start = create(start);
    display(start);
    //duplicateValues(start);
    freeList(start);
    return 0;
}

DNode* create(DNode* head){

    DNode* tail = NULL;
    DNode* newNode;
    int ans;

    do{
        newNode = (DNode*)malloc(sizeof(DNode));
        printf("\n\tEnter number and name: ");
        scanf("%d %s" , &newNode->no, newNode->name);

        newNode->next = NULL;
        newNode->prev = tail;

        if(head == NULL){
            head = newNode;
        }else{
            tail->next = newNode;
        }
        tail = newNode;

        printf("\n\tDo you want to enter more records: ");
        scanf("%d", &ans);
    } while(ans != 0);

    return head;
}

void display(DNode* head){

    if(!head){
        printf("\n]tList is empty.");
        return;
    }

    printf("\n\tDoubly Linked list.");
    for( ; head != NULL; head = head->next){
        printf("\n\tNumber = %d, Name = %s", head->no, head->name);
    }
}

void freeList(DNode* head){

    DNode* temp;
    while(temp != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n\tMemory freed successfully!");
}