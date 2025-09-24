
//write a c program to Create a doubly linked list, accept a key, and delete the node which contains the key element. 

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
DNode* deleteByKey(DNode*);
void freeList(DNode*);

int main(){

    DNode* start = NULL;
    start = create(start);

    start = deleteByKey(start);
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

DNode* deleteByKey(DNode* head){

    if(head == NULL){
        printf("List is already empty.");
        return NULL;
    }

    int key;
    printf("\n\tEnter the key element: ");
    scanf("%d", &key);

    DNode* p = head;

    if(head->no == key){
        head = head->next;
        free(p);
        return head;
    }

    while(p != NULL){

        if(p->no == key){
    
            if(p->prev != NULL)
                p->prev->next = p->next;
        
            if(p->next != NULL)
                p->next->prev = p->prev;
        
            free(p);
            return head;
        }
        p = p->next;
    }
    printf("\n\tKey not found!");
    return head;   
}
