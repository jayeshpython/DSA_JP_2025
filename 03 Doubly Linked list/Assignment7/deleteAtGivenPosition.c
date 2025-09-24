
//write a c program to Create a doubly linked list and Delete a node at given position.

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
DNode* deleteAtGivenPosition(DNode*);
void freeList(DNode*);

int main(){

    DNode* start = NULL;
    start = create(start);

    printf("\n\tLinked list after deleting head node.");
    start = deleteAtGivenPosition(start);
    display(start);
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

        printf("\tDo you want to enter more records: ");
        scanf("%d", &ans);

    }while(ans != 0);
    return head;
}

void display(DNode* head){

    if(!head){
        printf("\n\tList is empty.");
        return;
    }
    printf("\n\tDoubly linked list.");
    for( ; head != NULL; head = head->next){
        printf("\n\tNumer = %d, Name = %s", head->no, head->name);
    }
}

void freeList(DNode* head){
    DNode*  temp;

    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n\tMemory Frees successfully!");
}

DNode* deleteAtGivenPosition(DNode* head){

    DNode* p = head;
    if(head == NULL){
        printf("List is already empty.");
        return NULL;
    }

    int pos;
    printf("\n\tEnter position of node to be deleted: ");
    scanf("%d", &pos);

    if(pos == 1){
        head = head->next;
        free(p);
        return head;
    }

    for(int i = 1; p != NULL && i < pos; i++){
        p = p->next;
    }

    if(!p){
        printf("\n\tInvalid position!");
        return head;
    }

    if(p->prev != NULL){
        p->prev->next = p->next;
    }

    if(p->next != NULL){
        p->next->prev = p->prev;
    }

    free(p);
    printf("\n\tNode deleted successfully!");
    return head;

}