
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Singly{
    int no;
    char name[20];
    struct Singly* next;
}Node;

Node* create(Node*);
void display(Node*);
Node* deleteLastNode(Node*);
void freeList(Node*);

int main(){

    Node* start = NULL;
    start  = create(start);
    display(start);

    printf("\nDelete last node.");
    start = deleteLastNode(start);
    display(start);
    freeList(start);

    return 0;
}

Node* create(Node* head){

    Node* nw, *lst = NULL;
    int ans;

    do{
        nw = (Node*)malloc(sizeof(Node));
        printf("Enter number and name: ");
        scanf("%d %s", &nw->no, nw->name);

        nw->next = NULL;
        if(head == NULL)
        head = nw;
        else
        lst->next = nw;

        lst = nw;

        printf("To continue(1/0): ");
        scanf("%d", &ans);
    }
    while(ans != 0);
    return head;
}

void display(Node* head){

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

Node* deleteLastNode(Node* head){

    Node* p = head;

    if(head->next == NULL){
        free(head);
        return NULL;
    }

    while(p->next != NULL){
        
        p = p->next;
        if(p->next->next == NULL){
            free(p->next);
            p->next = NULL;
        }
    }
    return head;
}