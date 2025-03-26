
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNode1{
    int no;
    char name[20];
    struct DNode* prev;
    struct DNode* next;
}DNode1;

typedef struct DNode2{
    int no;
    char name[20];
    struct DNode* prev;
    struct DNode* next;
}DNode2;

DNode* create(DNode*);
void display(DNode*);

int main(){

    DNode* start = NULL;
    start = create(NULL);
    display(start);

    printf("\n\tLinked list after mergeing two linked list.");

    return 0;
}

DNode* create(DNode* head){

    DNode* newNode;
    DNode* tail = NULL;
    int ans;

    do{
        newNode = (DNode*)malloc(sizeof(DNode));
        printf("\n\tEnter number and name: ");
        scanf("%d %s", &newNode->no, newNode->name);

        newNode->next = NULL;
        newNode->prev = tail;

        if(head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;

        printf("\n\tDo you want to enter more records: ");
        scanf("%d", &ans);
    }while (ans != NULL);
    return head;
}

void display(DNode* head){

    if(!head){
        printf("\n\tList is empty.");
        return;
    }
    printf("\n\tDoubly Linked List.");
    for( ; head != NULL; head = head->next){
        printf("\n\tNumber = %d, Name = %s", head->no, head->name);
    }
}


DNode* create(DNode*);
void display(DNode*);

int main(){

    DNode* start = NULL;
    start = create(NULL);
    display(start);

    printf("\n\tLinked list after mergeing two linked list.");

    return 0;
}

DNode* create(DNode* head){

    DNode* newNode;
    DNode* tail = NULL;
    int ans;

    do{
        newNode = (DNode*)malloc(sizeof(DNode));
        printf("\n\tEnter number and name: ");
        scanf("%d %s", &newNode->no, newNode->name);

        newNode->next = NULL;
        newNode->prev = tail;

        if(head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;

        printf("\n\tDo you want to enter more records: ");
        scanf("%d", &ans);
    }while (ans != NULL);
    return head;
}

void display(DNode* head){

    if(!head){
        printf("\n\tList is empty.");
        return;
    }
    printf("\n\tDoubly Linked List.");
    for( ; head != NULL; head = head->next){
        printf("\n\tNumber = %d, Name = %s", head->no, head->name);
    }
}



