
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct singly{
    int no;
    char name[20];
    struct singly *next;
}sl;

sl* create(sl*);
void display(sl*);
void displayAlternate(sl*);
void swap(sl*);

int main(){

    sl* start = NULL;
    start = create(start);
    display(start);

    printf("\nDisplaying alternate elements");
    displayAlternate(start);

    printf("\nSwapping the alternate elements");
    swap(start);
    display(start);
    
    return 0;
}

sl* create(sl* head){

    sl* nw, *lst = NULL;
    int ans;

    do{
        nw = (sl*)malloc(sizeof(sl));
        printf("Enter no and name: ");
        scanf("%d %s", &nw->no, nw->name);

        nw->next = NULL;
        if(head == NULL)
        head = nw;
        else
        lst ->next = nw;

        lst = nw;

        printf("To continue(1/0): ");
        scanf("%d", &ans);
    }
    while(ans != 0);

    return head;
}

void display(sl* head){
    sl* temp = head;
    while (temp != NULL) {
        printf("\n\tRoll No: %d, Name: %s\n", temp->no, temp->name);
        temp = temp->next;
    }
}

void displayAlternate(sl* p){

    while(p != NULL){

        printf("\n\t Roll no = %d, Name = %s", p->no, p->name);
        if(p ->next != NULL)
        p = p->next->next;
        else  
        break;
    }
}

sl* swap(sl* p){

    while(p != NULL && p->next != NULL){

        sl* q = p->next;
        int temp_no;
        char temp_name;

        temp_no = p->no;
        p->no = q->no;
        q->no = temp_no;

        strcpy(temp_name, p->name);
        strcpy(p->name, q->name);
        strcpy(q->name, temp_name);
    
        p = q->next;
    }

}