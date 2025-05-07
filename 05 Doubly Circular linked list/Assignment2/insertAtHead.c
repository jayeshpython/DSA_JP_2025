

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Doubly{
    int no; 
    char name[20];
    struct Doubly* next;
    struct Doubly* prev;
}dsl;

dsl* create(dsl*);
void display(dsl*);
void freeList(dsl*);
dsl* insertAtHead(dsl*);

int main(){

    dsl* last = NULL;
    last = create(last);
    display(last);

    printf("\n\n\t Inserting new node at begining");
    last = insertAtHead(last);
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
            last->next = last;
            last->prev = last;
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

    if(!last){
        printf("\n\tList is empty.");
        return;
    }

    printf("\n\tDoubly linked list");
    dsl* p = last->next;

    do{
        printf("\n\tNumber = %d, Name = %s", p->no, p->name);
        p = p->next;
    } while (p != last->next);
}

void freeList(dsl* last){

    if(last == NULL)
    return;

    dsl* temp;
    dsl* p = last->next;

    do{
        temp = p;
        p = p->next;
        free(temp);
    } while(p != last->next);
    printf("\n\tMemory freed successfully.");
}

dsl* insertAtHead(dsl* last){

    if(last == NULL){
        printf("\n\tList is empty.");
        return NULL;
    }

    dsl* newNode = (dsl*)malloc(sizeof(dsl));
    printf("\n\tEnter number and name: ");
    scanf("%d %s", &newNode->no, newNode->name);

    if(last == NULL){
       newNode->next = newNode;
       newNode->prev = newNode;
       last = newNode;
       return last;
    }

    //Insert at beginning
    newNode->next = last->next;
    last->next->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
  
    return last;
}