

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Doubly {
    int no;
    char name[20];
    struct Doubly* next;
    struct Doubly* prev;
} dsl;

dsl* create(dsl*);
void display(dsl*);
dsl* insertion(dsl*);
dsl* deletion(dsl*);
void freeList(dsl*);

int main() {

    dsl* last = NULL;
    int choice;

    while (1) {
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insertion\n");
        printf("4. Deletion\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
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
        printf("\n\tList is empty");
        return;
    }
    dsl* p =last->next;

    do{
        printf("\n\tNumber = %d, Name = %s", p->no, p->name);
        p = p->next;
    } while(p != last->next);
}

void freeList(dsl* last){

    dsl* temp;
    dsl* p = last->next;

    do{
         temp = p;
        p = p->next;
        free(temp);
    } while(p != last);
    free(last);
    printf("\n\tMemory freed successfully!");
}


dsl* insertion(dsl* last){

    if(last == NULL){
        printf("\n\tList is empty.");
        return NULL;
    }
    dsl* newNode;
    newNode = (dsl*)malloc(sizeof(dsl));
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

dsl* deletion(dsl* last){

    if(last == NULL){
        printf("\n\tList is empty");
        return NULL;
    }

    int pos;
    printf("\n\tEnter positon to be deleted: ");
    scanf("%d", &pos);

    dsl* p = last->next;
    dsl* q = last;

    // delete When its only node
    if(last->next == last){
        free(p);
        return NULL;
    }

    //Delete first node
    if(pos == 1){
        last->next = p->next;
        p->next->prev = last;
        free(p);
        return last;
    }

    //Delete middle node
    for(int i = 1; i < pos && p != last; i++){
        p = p->next;
        q = q->next;
    }
    q->next = p->next;
    p->next->prev = q;

    //Delete last node
    if(p == last){
        last = q;
    }

    free(p);
    return last;

}