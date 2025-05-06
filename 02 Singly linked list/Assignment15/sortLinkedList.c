

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
Node* sortLinkedList(Node*);
void freeList(Node*);

int main(){

    Node* start = NULL;
    start = create(start);
    printf("\nLinked list before deleting");
    display(start);

    start = sortLinkedList(start);
    printf("\nLinked List after sorting.");
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

Node* sortLinkedList(Node* head){

    Node* p;
    Node* q;

    for(p = head; p != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->no > q->no){

                int temp;
                temp = p->no;
                p->no = q->no;
                q->no = temp;

                char tempName[20];
                strcpy(tempName, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, tempName);
            }
        }
    }
    return head;
}