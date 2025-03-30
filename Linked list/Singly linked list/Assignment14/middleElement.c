

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
void printMiddleNode(Node*);
void freeList(Node*);

int main(){

    Node* start = NULL;
    start = create(start);
    printf("\nLinked list before deleting");
    display(start);

    printMiddleNode(start);
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

void printMiddleNode(Node* head){

    Node* fast = head;
    Node* slow = head;
    Node* prev = NULL;

    if(head == NULL){
        return;
    }

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    printf("\n\tMiddle element of linked list:\n ");
    printf("\n\tNumber = %d, Name = %s", slow->no, slow->name);
   
}