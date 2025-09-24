

//write a c program to Create a Singly linked list and Insert a node at the last

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char name[20];
    int no;
    struct Node* next;
} Node;

Node* create(Node*);
void display(Node*);
void InsertAtLast(Node*);
void freeList(Node*);

int main() {
    Node* start = NULL;
    start = create(start);
    display(start);

    printf("\n\nInserting a new node at end of the list.");
    InsertAtLast(start); 
    display(start);
    freeList(start);

    return 0;
}

Node* create(Node* head) {
    Node* nw, *lst = NULL;
    int ans;

    do {
        nw = (Node*)malloc(sizeof(Node));
        printf("\nEnter name and number: ");
        scanf("%s %d", nw->name, &nw->no);

        nw->next = NULL;

        if (head == NULL) {
            head = nw;
        } else {
            lst->next = nw;
        }
        lst = nw;

        printf("To continue (1/0): ");
        scanf("%d", &ans);
    } while (ans != 0);

    return head;
}

void display(Node* head) {
    while (head != NULL) {
        printf("\n\tName: %s, Number: %d", head->name, head->no);
        head = head->next;
    }
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void InsertAtLast(Node* head) {
    
    Node* nw = (Node*)malloc(sizeof(Node));
    printf("\nEnter name and number for new node to insert: ");
    scanf("%s %d", nw->name, &nw->no);
    nw->next = NULL;

    if (head == NULL) {
        printf("\nList is empty. Cannot insert at end.\n");
        return;
    }

    while (head->next != NULL) {
        head = head->next;
    }
    head->next = nw;
}
