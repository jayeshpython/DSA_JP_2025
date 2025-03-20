

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[20];
    int no;
    struct Node *next;
}Node;

Node* create(Node*);
void display(Node*);
Node* InsertAtHead(Node*);
void freeList(Node*);

int main(){

    Node* start = NULL;
    start = create(start);
    display(start);

    printf("\n\nInserting new node at beginning.");
    start = InsertAtHead(start);
    display(start);
    freeList(start);

    return 0;
}

Node* create(Node* head){

    Node* nw, *lst = NULL;
    int ans;

do{
    nw = (Node*)malloc(sizeof(Node));
    printf("Enter name and no: ");
    scanf("%s %d", nw->name, &nw->no);

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

void display(Node* p){

    while(p != NULL){
        printf("\n\tName: %s, No: %d", p->name, p->no);
        p = p->next;
    }
}


void freeList(Node* head)
{
	Node* temp;
	
	while(head!=NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


Node* InsertAtHead(Node* head){
    Node* nw;

        nw = (Node*)malloc(sizeof(Node));
        printf("\nEnter name and number for new to node to insert: ");
        scanf("%s %d", nw->name, &nw->no);
        nw->next = NULL;

        if(head == NULL){   
            nw ->next = head;
            head = nw;
            return head;
        }

        for(int i = 1;)
}
