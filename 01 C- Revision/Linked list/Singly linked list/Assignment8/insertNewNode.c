

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[20];
    int no;
    struct Node* next;
}Node;

Node* create(Node*);
void display(Node*);
Node* insertNewNode(Node*);
void freeList(Node*);

int main(){

    Node* start = NULL;
    start = create(start);
    display(start);

    start = insertNewNode(start);
    printf("\n\nLinked list after inserting new node");
    display(start);
    freeList(start);

    return 0;
}

Node* create(Node* head){

    Node* nw, *lst = NULL;
    int ans;

    do{
        nw = (Node*)malloc(sizeof(Node));
        printf("Enter name and number: ");
        scanf("%s %d", nw->name, &nw->no);

        nw->next = NULL;

        if(head == NULL){
            head = nw;
        }
        else{
            lst->next = nw;
        }
        lst = nw;

        printf("To continue(1/0): ");
        scanf("%d", &ans);
    } while(ans != 0);
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

Node* insertNewNode(Node* head){

    Node* nw, *p = head;
    int key, flag =0;

    printf("\nEnter position of node to add: ");
    scanf("%d", &key);

    nw = (Node*)malloc(sizeof(Node));
    printf("\nEnter name and number to insert: ");
    scanf("%s %d", nw->name, &nw->no);

    // Insert at head
    if(head == NULL){
        nw->next = head;
        head = nw;
        return head;
    }

    for(int i = 1; i< key - 1 && p != NULL; p = p->next, i++);

    if(p != NULL){
        nw->next = p->next;
        p->next = nw;
    }
    else{
        printf("\nInvalid key option: ");
        free(nw);
    }
    return head;

}
