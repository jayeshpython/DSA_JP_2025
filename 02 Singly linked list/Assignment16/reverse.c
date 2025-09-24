
/*
"write a c program to Create a Singly linked list and Display it in reverse order (Use Normal Function)
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_NULL_| 
O/P :
------  
4 DD
3 CC
2 BB
1 AA
*/

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
Node* reverseList(Node*);
void freeList(Node*);

int main(){

    Node* start = NULL;
    start = create(start);
    display(start);

    start = reverseList(start);
    printf("\n\nLinked list after reversing");
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

// Reverse Linked List
Node* reverseList(Node* head) {
    Node* q = NULL;
    Node* p = head;
    Node* next = NULL;

    while (p != NULL) {
        next = p->next;  
        p->next = q; 
        q = p;        
        p = next;       
    }

    return q; 
}

