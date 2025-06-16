
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Doubly{
    int no;
    struct Doubly* next, *prev;
}dsl;

dsl* create(dsl*);
void display(dsl*);
void freeList(dsl*);
dsl* deletion(dsl*);

int main(){

    dsl* last = NULL;
    last = create(last);

    printf("Displaying doubly circular linked list");
    display(last);

    last = deletion(last);
    display(last);
    freeList(last);

    return 0;
}

dsl* create(dsl* last){

    dsl* newNode;
    int ans;

    do{
        newNode = (dsl*)malloc(sizeof(dsl));
        printf("Enter number: ");
        scanf("%d", &newNode->no);

        newNode->next = NULL;
        newNode->prev = last;

        if(last == NULL){
            last = newNode;
            last->next = last;
            last->prev = last;
        }
        else{
            last->next->prev = newNode;
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        printf("\n\tDo you want to enter more records: ");
        scanf("%d", &ans);
    }while(ans != 0);
    return last;
}

void display(dsl* last){

    if(!last){
        printf("list is empty.");
        return;
    }

    dsl* p = last->next;
    do{
        printf("\nNumber = %d", p->no);
        p = p->next;
    }while(p != last->next);
}

void freeList(dsl* last){

    if(!last){
        printf("\nList is empty.");
        return;
    }

    dsl* temp;
    dsl* p = last->next;
    do{
        temp = p;
        p = p->next;
        free(temp);
    }while(p != last);

    free(last);
    printf("\nMemory freed successfully");
}

dsl* deletion(dsl *last)
{
    if (last == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    int pos;
    printf("\nEnter position of node to delete: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position.\n");
        return last;
    }

    dsl *p = last->next, *q = NULL;
    int i = 1;

    if (pos == 1) {
        if (p == last) {
            free(p);
            return NULL;
        }
        last->next = p->next;
        p->next->prev = last;
        free(p);
        return last;
    }

    while (i < pos && p != last) {
        q = p;
        p = p->next;
        i++;
    }

    if (i < pos) {
        printf("Invalid position.\n");
        return last;
    }

    q->next = p->next;
    p->next->prev = q;

    if (p == last)
        last = q;

    free(p);
    return last;
}
