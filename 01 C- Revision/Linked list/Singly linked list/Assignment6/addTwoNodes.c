
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
void addTwoNode(Node*);
void freeList(Node*);

int main(){

    Node* start = NULL;
    start = create(start);
    display(start);

    printf("\nAdding two nodes into third node");
    addTwoNode(start);
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

void addTwoNode(Node* head){

    Node* p = head, *q;
    Node* nw;

    while(p != NULL && p->next != NULL){

        q = p->next;
        nw = (Node*)malloc(sizeof(Node));

        nw->no = p->no + q->no;
        strcpy(nw -> name, p->name);
        strcat(nw -> name, q -> name);

        nw->next = q->next;
        q->next = nw;
        p = nw->next;
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