
//write a c program to Create a Singly linked list and Delete the node at the Head position

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
Node* deleteHeadNode(Node*);
void freeList(Node*);

int main() {
    Node* start = NULL;
    start = create(start);
    printf("\nLinked list before deleting");
    display(start);

    printf("\n\nLinked list after deleting head node.");
    start = deleteHeadNode(start);  
    display(start);
    freeList(start);

    return 0;
}

Node* create(Node* head) {
    Node* nw, *lst = NULL;
    int ans;

    do {
        nw = (Node*)malloc(sizeof(Node));
        printf("Enter name and number: ");
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

Node* deleteHeadNode(Node* head){

    Node* p = head;
    if(head == NULL){
        printf("List is already empty.");
        return NULL;
    }
     
    head = head->next;
    free(p);
    return head;
}