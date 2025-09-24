
//write a c program to create two doubly linked lists, sort them individually and then merge the two sorted lists

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNode{
    int no;
    char name[20];
    struct DNode* prev;
    struct DNode* next;
}DNode;

DNode* create(DNode*);
void display(DNode*);
void sort(DNode*);
DNode* merge(DNode*, DNode*);
void freeList(DNode*);

int main(){

    DNode* start1 = NULL;
    DNode* start2 = NULL;
    DNode* merged = NULL;

    printf("\n\n\tCreating first linked list: ");
    start1 = create(start1);

    printf("\n\n\tCreating second linked list: ");
    start2 = create(start2);

    display(start1);
    display(start2);

    merged = merge(start1, start2);
    printf("\n\n\tDisplaying merged list: ");
    display(merged);

    sort(merged);
    printf("\n\n\tDisplaying merged and sorted list: ");
    display(merged);

    freeList(start1);
    freeList(start2);
    freeList(merged);
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
    }while (ans != 0);
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

void freeList(DNode* head){
    DNode*  temp;

    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n\tMemory Frees successfully!");
}

DNode* merge(DNode* list1, DNode* list2){

    if(!list1){
        printf("\n\tList1 is empty.");
        return list2;
    }
    if(!list2){
        printf("\n\tList2 is empty.");
        return list1;
    }
    
    DNode* p = list1;
    while(p->next != NULL){
        p = p->next;
    }
    DNode* temp = list2;
    p->next = temp;
    temp->prev = p;

    return list1;
}

void sort(DNode* head){

    DNode* p = head;
    DNode* q;

    for(p = head; p != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){

            if(p->no > q->no){
                int temp;
                temp = p->no;
                p->no = q->no;
                q->no = temp;

                char tempName[20];
                strcpy(tempName, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, tempName);
            }
        }
    }
}