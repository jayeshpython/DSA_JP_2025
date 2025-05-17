

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Doubly{
    int no;
    char name[20];
    struct Doubly* next;
    struct Doubly* prev;
}dsl;

dsl* create(dsl*);
void display(dsl*);
void freeList(dsl*);
dsl* insertAtPosition(dsl*);

int main(){

    dsl* last = NULL;
    last = create(last);
    display(last);

    printf("\n\n\tInserting a new node in linked list");
    last = insertAtPosition(last);
    display(last);
    freeList(last);
    return 0;
}

dsl* create(dsl* last){

    dsl* newNode;
    int ans;

    do{
        newNode = (dsl*)malloc(sizeof(dsl));
        printf("\n\tEnter number and name: ");
        scanf("%d %s", &newNode->no, newNode->name);

        newNode->next = NULL;
        newNode->prev = last;

        if(last == NULL){
            last = newNode;
            last->next = newNode;
            last->prev = newNode;
        }
        else{
            newNode->next = last->next;
            last->next->prev = newNode;
            last->next = newNode;
            last = newNode;
        }
        printf("\n\tDo you want to enter more records: ");
        scanf("%d", &ans);
    } while(ans != 0);
    return last;
}

void display(dsl* last){

    if(last == NULL){
        printf("\n\tList is empty.");
        return;
    }

    printf("\n\tDoubly linked list.");
    dsl* p = last->next;

   do{
    printf("\n\tNumber = %d,Name = %s", p->no,p->name);
    p = p->next;
   }while(p != last->next);
}

void freeList(dsl* last){

    if(last == NULL){
        printf("\n\tList is empty");
        return;
    }

    dsl* temp;
    dsl* p = last->next;

   do{
        temp = p;
        p = p->next;
        free(temp);
   } while(p != last->next);
}

dsl* insertAtPosition(dsl* last){

    dsl* newNode;
    newNode = (dsl*)malloc(sizeof(dsl));
    if (!newNode) {
        printf("\n\tMemory allocation failed.");
        return last;
    }
    printf("\n\tEnter Number and name: ");
    scanf("%d %s", &newNode->no, newNode->name);

    int pos;
    printf("\n\tEnter position to inert at ");
    scanf("%d", &pos);

    //When list is empty
    if(last == NULL){
        last->next = last;
        last->prev = last;
        return newNode;
    }

    //Insert at first positon
    if(pos == 1){
        newNode->next = last->next;
        last->next->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
        return last;
    }

    //Insert at given position
    dsl* p = last->next;
    int i;
    for( i = 1; i < pos-1 && p != last; i++){
        p = p->next;
    }

    // If position is out of range
    if ( p == last && i< pos-1) {
        printf("\n\tPosition is out of range.");
        free(newNode);
        return last;
    }

    newNode->next = p->next;
    newNode->prev = p;
    p->next->prev = newNode;
    p->next = newNode;

    //Inserting at last position
    if(p == last){
        last = newNode;
    }

    return last;
}