

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Singly{
    char name[20];
    int no;
    struct Singly *next;
}sl;

sl* create(sl*);
void display(sl*);
void searchNode(sl*);
void freeList(sl*);

int main(){

    sl* start = NULL;
    start = create(start);
    display(start);

    printf("\nASearching a particular node");
    searchNode(start);
    freeList(sl*);

    return 0;
}

sl* create(sl* head){

    sl* nw, *lst = NULL;
    int ans;

    do{
        nw = (sl*)malloc(sizeof(sl));
        printf("Enter name and no: ");
        scanf("%s %d", nw->name, &nw->no);

        nw->next = NULL;
        if(head == NULL){
            head = nw;
        }
        else
        lst->next = nw;

        lst = nw;

        printf("To continue(1/0): ");
        scanf("%d", &ans);
    }
    while(ans!=0);
    return head;
}

void display(sl* p){

    while(p != NULL){
        printf("\n\tName: %s, No: %d", p->name, p->no);
        p = p->next;
    }
}

void searchNode(sl* head){

    sl* p =head;
    int key, flag=0;
    printf("\n\nEnter key: ");
    scanf("%d", &key);

    if(p == NULL){
        printf("Linked list is emplty.");
    }

    while(p != NULL){
        if(p -> no == key){
            printf("\nName: %s", p->name);
            printf("\nNumber: %d", p->no);

            flag =1;
            break;
        }
        p = p->next;
    }
        if(flag == 0){
            printf("\nNode note found.");
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



