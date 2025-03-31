

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNode {
    int no;
    char name[20];
    struct DNode* next;
    struct DNode* prev;
} DNode;

DNode* create(DNode*);
DNode* insertion(DNode*);
DNode* deletion(DNode*);
void display(DNode*);
void printReverse(DNode*);
void freeList(DNode*);

int main() {

    int choice;
    DNode* start = NULL;

    while (1) {
        printf("\n\n\t*********Menu Driven Program - Doubly Linked List******");
        printf("\n\t1. Create List.");
        printf("\n\t2. Insert Node.");
        printf("\n\t3. Delete Node.");
        printf("\n\t4. Print List.");
        printf("\n\t5. Print Reverse List.");
        printf("\n\t6. Exit.");
        printf("\n\tEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = create(start);
                display(start);
                break;

            case 2:
                start = insertion(start);
                display(start);
                break;

            case 3:
                start = deletion(start);
                display(start);
                break;

            case 4:
                display(start);
                break;

            case 5:
                printReverse(start);
                break;

            case 6:
                freeList(start);
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}

DNode* create(DNode* head) {

    DNode* tail = NULL;
    DNode* newNode;
    int ans;

    do {
        newNode = (DNode*)malloc(sizeof(DNode));
        if (!newNode) {
            printf("\n\tMemory allocation failed.");
            return head;
        }

        printf("\n\tEnter number and name: ");
        scanf("%d %s", &newNode->no, newNode->name);

        newNode->next = NULL;
        newNode->prev = tail;

        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;

        printf("\n\tDo you want to enter more records (1(yes) / 0(no)) : ");
        scanf("%d", &ans);
    } while (ans != 0);

    return head;
}

void display(DNode* head) {

    if (!head) {
        printf("\n\tList is empty.");
        return;
    }
    printf("\n\tDoubly Linked List:");

    for (; head != NULL; head = head->next) {
        printf("\n\t Number: %d, Name: %s", head->no, head->name);
    }
}

void printReverse(DNode* head) {

    if (!head) {
        printf("\n\tList is empty.");
        return;
    }

    DNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    printf("\n\tReversed List:");
    while (tail != NULL) {
        printf("\n\t Number: %d, Name: %s", tail->no, tail->name);
        tail = tail->prev;
    }
}

void freeList(DNode* head) {

    DNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n\tMemory Freed Successfully!\n");
}

DNode* insertion(DNode* head) {

    DNode* newNode;
    newNode = (DNode*)malloc(sizeof(DNode));

    if (!newNode) {
        printf("\n\tMemory allocation failed.");
        return head;
    }

    printf("\n\tEnter number and name to insert: ");
    scanf("%d %s", &newNode->no, newNode->name);

    int pos;
    printf("\n\tEnter position to insert new node: ");
    scanf("%d", &pos);

    newNode->prev = NULL;
    newNode->next = NULL;

    // Insert at head
    if (pos == 1) {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        return newNode;  
    }

    DNode* p = head;
    for (int i = 1; p && i < pos - 1; i++)
        p = p->next;

    if (p == NULL) {
        printf("\n\tInvalid position!");
        free(newNode);
        return head;
    }

    newNode->next = p->next;
    if (p->next != NULL)
        p->next->prev = newNode;

    p->next = newNode;
    newNode->prev = p;

    return head;
}

DNode* deletion(DNode* head) {
    
    if (head == NULL) {
        printf("\n\tList is already empty.");
        return NULL;
    }

    int pos;
    printf("\n\tEnter position of node to be deleted: ");
    scanf("%d", &pos);

    DNode* p = head;

    if (pos == 1) {
        head = head->next;
        if (head)
            head->prev = NULL;
        free(p);
        return head;
    }

    for (int i = 1; p != NULL && i < pos; i++) {
        p = p->next;
    }

    if (!p) {
        printf("\n\tInvalid position!");
        return head;
    }

    if (p->prev != NULL)
        p->prev->next = p->next;
    if (p->next != NULL)
        p->next->prev = p->prev;

    free(p);
    printf("\n\tNode deleted successfully!");
    return head;
}
