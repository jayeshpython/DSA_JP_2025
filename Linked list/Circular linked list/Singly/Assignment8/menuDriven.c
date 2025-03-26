

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Singly{
    int no;
    char name[20];
    struct Singly* next;
}scl;

scl* create(scl*);
void display(scl*);
scl* insertion(scl*);
scl* deletion(scl*);
void freeList(scl*);

int main(){

    int choice;
    scl* last = NULL;
     
    while(1){

        printf("\n\t*******Menu Driven Program - Circular Singly Linked List*******");
        printf("\n\t1. Create List");
        printf("\n\t2. Print List");
        printf("\n\t3. Insertion");
        printf("\n\t4. Deletion");
        printf("\n\t5. Exit");
        printf("\n\tEnter your chice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
            last = create(last);
            break;

            case 2:
            display(last);
            break;

            case 3:
            last = insertion(last);
            display(last);
            break;

            case 4:
            last = deletion(last);
            display(last);
            break;

            case 5:
            freeList(last);
            exit(0);

            default:
            printf("\n\tInvalid choice! Please try again");
        }
    }
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
        printf("\n\tDo yo want to enter more records(1/0): ");
        scanf("%d", &ans);
    } while(ans != 0);
    return last;
}

void display(scl* last){

    if(last == NULL){
        printf("\n\tList is empty.");
        return;
    }

    scl* p = last->next;
    printf("\n\tSingly linked list.");

    do{
        printf("\n\tNumber = %d, Name = %s", p->no, p->name);
        p = p->next;
    } while(p != last->next);
}

void freeList(scl* last){

    scl* p;
    scl* temp = last->next;

    do{
        p = temp;
        temp = temp->next;
        free(p);
    } while(p != last->next);
}

scl* insertion(scl* last){

    if(last == NULL){
        printf("\n\tList is empty.");
        return last;
    }

    scl* newNode;
    newNode = (scl*)malloc(sizeof(scl));
    printf("\n\tEnter number and name: ");
    scanf("%d %s", &newNode->no, newNode->name);

    int pos;
    printf("\n\tEnter position to insert the node: ");
    scanf("%d", &pos);

     // Insert when list is empty
    if (last == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    //Insert at first position
    if(pos == 1){
        newNode->next = last->next;
        last->next = newNode;
        return last;
    }

    //Insert at given position
    scl* p = last->next;
    int i;
    for(i = 1; i < pos-1 && p != last; i++){
        p = p->next;
    }

    newNode->next = p->next;
    p->next = newNode;

    //Insert at last positon
    if(p == last){
        last = newNode;
    }
    return last;
}


scl* deletion(scl* last){

    if(last == NULL){
        printf("\n\tList is empty.");
        return NULL;
    }

    int pos;
    printf("\n\tEnter position of node to be deleted: ");
    scanf("%d", &pos);

    scl* p = last->next;
    scl* q = last;
    //delete when its only one node
    if(last->next == last){
        free(p);
        return NULL;
    }

    scl* temp = last->next;
    //deleting first node
    if(pos == 1){
        last->next = temp->next;
        free(temp);
        return last;
    }

    // deleting a middle node
    for(int i = 1; i < pos && p != last; i++){
        p = p->next;
        q = q->next;
    }
    q->next = p->next;
    
    //deleting last node
    if(p == last){
        q->next = p->next;
        last = q;
    }
    free(p);
    return last;
    
}
