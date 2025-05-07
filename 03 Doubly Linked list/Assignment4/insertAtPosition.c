
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
void printList(DNode*);
DNode* insertAtPosition(DNode*);
void freeList(DNode*);

int main(){

    DNode* start = NULL;
    start = create(start);
    printList(start);

    printf("\n\tInserting new node at given position.");
    start = insertAtPosition(start);
    printList(start);
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
        scanf("%d %s", &newNode->no, newNode->name);

        newNode->next = NULL;
        newNode->prev = tail;

        if(head == NULL){
            head = newNode;
        }
        else{
            tail->next = newNode;
        }
        tail = newNode;

        printf("\n\tDo you want to enter more records (1(yes) / 0(no)) : ");
        scanf("%d", &ans);
    }while(ans != 0);
    return head;
}

void printList(DNode* head){

    if(!head){
        printf("\n\tList is empty.");
        return;
    }
    printf("\n\tDoubly Linked List.");

    for( ; head != NULL; head = head->next){
        printf("\n\t Number: %d, Name: %s", head->no, head->name);
    }
}

void freeList(DNode* head) {
    DNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n\tMemory Freed Successfully!\n");
}

DNode* insertAtPosition(DNode* head){

    DNode* newNode;
    newNode = (DNode*)malloc(sizeof(DNode));
    printf("\n\tEnter number and name to insert: ");
    scanf("%d %s", &newNode->no, newNode->name);

    if(!newNode){
        printf("\n\tMemory allocation failed.");
        return head;
    }

    int pos;
    printf("\n\tEnter position to insert new node: ");
    scanf("%d", &pos);

    newNode->prev = NULL;
    newNode->next = NULL;

    if (pos <= 0) {
        printf("\n\tInvalid position!");
        free(newNode);
        return head;
    }

    //Insert at head
    if(pos == 1){
        newNode->next = head;

        if(head != NULL)
        head->prev = newNode;
        
        head = newNode;
        return head;
    }

    DNode* p = head;
    for(int i = 1; p->next && i < pos-1; i++){
        p = p->next;
    }

    newNode->next = p->next;
    if(p->next != NULL){
        p->next->prev = newNode;
    }
    p->next = newNode;
    newNode->prev = p;

    return head;
}
