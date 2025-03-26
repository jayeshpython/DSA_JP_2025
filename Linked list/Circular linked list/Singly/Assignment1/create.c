

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Singly{
    int no;
    char name[30];
    struct Singly* next;
}scl;

scl* create(scl*);
void display(scl*);

int main(){

    scl* last = NULL;
    last = create(last);
    display(last);
    return 0;
}

scl* create(scl* last){

    scl* newNode;
    int ans;

    do{
        newNode = (scl*)malloc(sizeof(scl));
        printf("\n\tEnter number and name: ");
        scanf("%d %s", &newNode->no, newNode->name);

        newNode->next = NULL;

        if(last == NULL){
            last = newNode;
            last->next = last;
        }
        else{
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        printf("\n\tDp you want to enter more records: ");
        scanf("%d", &ans);
    } while(ans != 0);
    return last;
}

void display(scl* last){

    if(last == NULL){
        printf("\n\tList is empty.");
        return ;
    }
    scl* p = last->next;
    printf("\n\tSingly Circular Linked List.");

    do{
        printf("\n\tNumber = %d, Name = %s", p->no, p->name);
        p = p->next;
    } while(p != last->next);
}

void freeList(scl* last){

    if(last == NULL){
        printf("\n\tMemory freed successfully!\n");return;
    }
    scl* temp = last->next;
    scl* p;

    do{
        p = temp;
        temp = temp->next;
        free(p);
    } while(temp != last->next);
    printf("\n\tMemory freed successfully!");
}

