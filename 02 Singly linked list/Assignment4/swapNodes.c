

/*
"write a c program to Create a Singly linked list and swap the two consecutive nodes 
	  
I/P  ---->   |_1_|_AA_|_100_| --> |_2_|_BB_|_200_| --> |_3_|_CC_|_300_| --> |_4_|_DD_|_400_| --> |_5_|_EE_|_500_| --> |_6_|_FF_|_NULL_|  


O/P  ---->   |_2_|_BB_|_100_| --> |_1_|_AA_|_200_| --> |_4_|_DD_|_300_| --> |_3_|_CC_|_400_| --> |_6_|_FF_|_500_| --> |_5_|_EE_|_NULL_|
*/

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
void swapNodes(sl*);

int main(){

    sl* start = NULL;
    start = create(start);
    display(start);

    printf("\nSwapping two consecutive node");
    swapNodes(start);
    display(start);

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

void swapNodes(sl* p){

    while(p != NULL && p->next != NULL){

        int temp_no;
        char temp_name[20];

        sl* q = p->next;

        temp_no = p->no;
        p->no = q->no;
        q->no = temp_no;

        strcpy(temp_name, p->name);
        strcpy(p->name, q->name);
        strcpy(q->name, temp_name);

        p = q->next;
    }
}