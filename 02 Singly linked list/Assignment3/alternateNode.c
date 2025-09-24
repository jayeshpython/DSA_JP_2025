

/*
"write a c program to Create a Singly linked list and Display the alternate nodes 

I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_NULL_|. 

O/P  ---->  |_1_|_AA_|_100_| --> |_3_|_CC_|_300_| --> |_5_|_EE_|_NULL_|
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Singly{
    char name[20];
    int no;
    struct Singly* next;
}sl;

sl* create(sl*);
void display(sl*);
void alternateNode(sl*);

int main(){

    sl* start = NULL;
    start = create(start);
    display(start);
    
    printf("\nPrinting alternate node");
    alternateNode(start);

    return 0;
}

sl* create (sl* head){

    sl* nw, *lst = NULL;
    int ans;

do{
    nw = (sl*)malloc(sizeof(sl));
    printf("Enter name and no: ");
    scanf("%s %d", nw->name, &nw->no);

    nw ->next = NULL;
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

void display(sl* p){

    while(p != NULL){
        printf("\n\tName: %s, No: %d\n", p->name, p->no);
        p = p->next;
    }
}

void alternateNode(sl* p){

    while(p != NULL){
        printf("\n\t Roll no = %d, Name = %s", p->no, p->name);

        if(p->next != NULL){
            p = p->next->next;
        }
        else
        break;
    }
}