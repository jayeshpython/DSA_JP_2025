

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
Node* deleteNodeAtAnyPosition(Node*);
void freeList(Node*);

int main(){

    Node* start = NULL;
    start = create(start);
    printf("\nLinked list before deleting");
    display(start);

    start = deleteNodeAtAnyPosition(start);
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

Node* deleteNodeAtAnyPosition(Node* head){

    Node* temp = head;
    Node* p = head;
    Node* q = head->next;
    int pos, flag =0;

    printf("\nEnter position of node to delete: ");
    scanf("%d", &pos);

    if(head == NULL){
        printf("\nList is empty.");
        return head;
    }

    if( pos == 1){
        head = head-> next;
        free(p);
       return head; 
    }

     // Method 1
    for(int i = 2; q != NULL && i <= pos; i++){
        
        if(i == pos){
            p->next = q->next;
            free(q);
            return head;
        }
        p = q;
        q = q->next;
    }
    
    if(p->next == NULL){
        printf("\nInvalid position!");
        return head;
    }
    return head;
}


