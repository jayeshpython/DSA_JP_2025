

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Singly {
    int no;
    char name[20];
    struct Singly* next;
    struct Singly* prev;
} sll;

sll* create(sll*);
void display(sll*);
void freeList(sll*);
sll* reverse(sll*);

int main() {
    sll* last = NULL;
    last = create(last);
    display(last);

    printf("\n\n\tLinked list after reversing.");
    last = reverse(last);
    display(last);

    freeList(last);
    return 0;
}

sll* create(sll* last) {
    sll* newNode;
    int ans;

    do {
        newNode = (sll*)malloc(sizeof(sll));
        printf("\n\tEnter number and name: ");
        scanf("%d %s", &newNode->no, newNode->name);

        newNode->next = NULL;
        newNode->prev = last;

        if (last == NULL) {
            last = newNode;
            last->next = last;
            last->prev = last;
        } else {
            newNode->next = last->next;
            last->next->prev = newNode;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }

        printf("\n\tDo you want to continue(1/0): ");
        scanf("%d", &ans);
    } while (ans != 0);
    return last;
}

void display(sll* last) {
    if (!last) {
        printf("\n\tList is empty");
        return;
    }

    sll* p = last->next;
    printf("\n\tCircular doubly linked list");
    do {
        printf("\n\tNumber = %d, Name = %s", p->no, p->name);
        p = p->next;
    } while (p != last->next);
}

void freeList(sll* last) {
    if (!last) return;

    sll* p = last->next;
    sll* temp;

    do {
        temp = p;
        p = p->next;
        free(temp);
    } while (p != last->next);
    printf("\n\tMemory freed successfully");
}

sll* reverse(sll* last) {
    if (!last) {
        printf("\n\tList is empty.");
        return NULL;
    }

    sll* current = last->next;
    sll* temp;

    while()
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != last->next);

    last = last->next;
    return last;
}
