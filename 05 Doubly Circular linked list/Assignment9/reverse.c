

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Doubly {
    int no;
    char name[20];
    struct Doubly* next;
    struct Doubly* prev;
} dsl;

dsl* create(dsl*);
dsl* reverse(dsl*);
void display(dsl*);
void freeList(dsl*);

int main() {
    dsl* last = NULL;
    last = create(last);
    display(last);

    printf("\n\n\tReversing the Doubly Circular Linked List...");
    last = reverse(last);
    display(last);

    freeList(last);
    return 0;
}

dsl* create(dsl* last) {
    dsl* newNode;
    int ans;

    do {
        newNode = (dsl*)malloc(sizeof(dsl));
        printf("\n\tEnter number and name: ");
        scanf("%d %s", &newNode->no, newNode->name);

        if (last == NULL) {
            newNode->next = newNode;
            newNode->prev = newNode;
            last = newNode;
        } else {
            newNode->next = last->next;
            newNode->prev = last;
            last->next->prev = newNode;
            last->next = newNode;
            last = newNode;
        }

        printf("\n\tDo you want to enter more records (1/0)? ");
        scanf("%d", &ans);
    } while (ans != 0);

    return last;
}

void display(dsl* last) {
    if (last == NULL) {
        printf("\n\tList is empty.");
        return;
    }

    printf("\n\tDoubly Circular Linked List:");
    dsl* p = last->next;
    do {
        printf("\n\tNumber = %d, Name = %s", p->no, p->name);
        p = p->next;
    } while (p != last->next);
}

dsl* reverse(dsl* last){

    if(!last){
        printf("\nList is EMpty");
        return NULL;
    }
    else if(last->next == last){
        printf("\nSingle Node");
        return last;
    }

    dsl* p = last,*q = last->next;
    do{
        p ->next = p->prev;
        p->prev = q;
        p = q;
        q = p->next;
    }while(p != last);
    return last;
}


void freeList(dsl* last) {
    if (last == NULL)
        return;

    dsl* p = last->next;
    last->next = NULL; 

    while (p != NULL) {
        dsl* temp = p;
        p = p->next;
        free(temp);
    }

    printf("\n\tMemory freed successfully.");
}
