
//write a c program to Create a Singly linked list and Delete the node depending on user input key/value

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
Node* deleteNodeByKey(Node*);
void freeList(Node*);

int main(){

    Node* start = NULL;
    start = create(start);
    printf("\nLinked list before deleting");
    display(start);

    start = deleteNodeByKey(start);
    printf("\nLinked List after deleting node.");
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

Node* deleteNodeByKey(Node* head){

    Node* p = head;
    Node* q = head;
    int key, flag = 0;

    if (head == NULL) {
        printf("\nList is empty!\n");
        return NULL;
    }

    printf("\nEnter the key element: ");
    scanf("%d", &key);

    if(head->no == key ){
        head = head-> next;
        free(p);
       return head; 
    }

   while(p->next != NULL){
        q = p->next;

        if(q->no == key){
            p->next = q->next;
            free(q);
            flag = 1;
            return head;
        }
        
        p = p->next;
   }
   if(flag == 0){
        printf("\nKey %d do not found in the list. ", key);
   }
}

   