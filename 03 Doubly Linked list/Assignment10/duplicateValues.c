
//write a c program to Delete duplicate values(nodes) in doubly linked list.

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
DNode* duplicateValues(DNode*);

int main(){

    DNode* start = NULL;
    start = create(start);
    display(start);

    printf("\n\tLinked list after deleting duplicate elements: ");
    start = duplicateValues(start);
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
        printf("\n]\tList is empty.");
        return;
    }

    printf("\n\tDoubly Linked list.");
    for( ; head != NULL; head = head->next){
        printf("\n\tNumber = %d, Name = %s", head->no, head->name);
    }
}

void freeList(DNode* head){

    DNode* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n\tMemory freed successfully!");
}

DNode* duplicateValues(DNode* head){

    if(!head){
        printf("\n\tLinked list is empty.");
        return NULL;
    }

    DNode* p = head;
    DNode* q = head;
    int temp;
    char tempName[20];

    for(p = head ; p != NULL ; p = p->next){
        for( q = p->next ; q != NULL; q = q->next){

            if(p->no > q->no){
                temp = p->no;
                p->no = q->no;
                q->no = temp;

                strcpy(tempName, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, tempName);
            }
        }
    }

    for(DNode* p = head; p != NULL && p->next != NULL; p = p->next){
        if(p->no == p->next->no){

            DNode* q = p->next;
            p->next = q->next;

            if(q->next != NULL){
                q->next->prev = p;
            }
            free(q);
            p = head;
        }
    }
    return head;
}