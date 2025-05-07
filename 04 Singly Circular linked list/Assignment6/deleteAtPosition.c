

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Singly {
    int no;
    char name[20];
    struct Singly* next;
} scl;

scl* create(scl*);
void display(scl*);
scl* deletion(scl*);
void freeList(scl*);

int main() {
    scl* last = NULL;
    last = create(last);
    display(last);
    
    printf("\n\n\tLinked list after deleting node.");
    last = deletion(last);
    display(last);

    freeList(last);

    return 0;
}

scl* create(scl* last) {

    scl* newNode;
    int ans;

    do {
        newNode = (scl*)malloc(sizeof(scl));
        printf("\n\tEnter number and name: ");
        scanf("%d %s", &newNode->no, newNode->name);

        if (last == NULL) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }

        printf("\n\tDo you want to enter more records (1/0): ");
        scanf("%d", &ans);
    } while (ans != 0);
    
    return last;
}

void display(scl* last) {

    if (last == NULL) {
        printf("\n\tList is empty.");
        return;
    }

    scl* p = last->next;
    printf("\n\tCircular Linked List:\n");

    do {
        printf("\t%d %s\n", p->no, p->name);
        p = p->next;
    } while (p != last->next);
}

void freeList(scl* last) {

    if (last == NULL) {
        printf("\n\tMemory Freed Successfully!\n");
        return;
    }

    scl* temp = last->next;
    scl* p;

    do {
        p = temp;
        temp = temp->next;
        free(p);
    } while (temp != last->next);

    printf("\n\tMemory Freed Successfully!\n");
}
        
scl* deletion(scl* last){

    if(last == NULL){
        printf("\n\tList is empty.");
        return NULL;
    }

    int key;
    printf("\n\tEnter key to delete: ");
    scanf("%d", &key);

    scl* p = last->next;
    scl* q = last;

    //when only one node
    if(last->next == last && last->no == key){
        free(last);
        return NULL;
    }

    while(p != last){

        if(p->no == key){
            q->next = p->next;
            free(p);
            return last;
        }
        q = p;
        p = p->next;
    }
      // delete last node
    if(last->no == key){
        q->next = p->next;
        free(last);
        last = p;
        return last;
    }
    printf("\n\tKey not found.");
    return last;
}

