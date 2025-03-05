



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singly {
    int no;
    char name[20];
    struct singly *next;
} sl;

sl* create(sl*);
void display(sl*);
void displayAlternate(sl*);
void swap(sl*);
void add(sl*);

int main() {
    sl* start = NULL;
    start = create(start);
    display(start);
    
    printf("\nDislaying alternate elements");
    displayAlternate(start);

    printf("\nSwapping two consecutive node");
    swap(start);
    display(start);

    printf("\nAdding two nodes into third node");
    add(start);
    display(start);
    return 0;
}

sl* create(sl* head) {
    sl *nw, *lst = NULL;
    int ans;
    
    do {
        nw = (sl*)malloc(sizeof(sl));
        printf("Enter roll no and name: ");
        scanf("%d %s", &nw->no, nw->name);
        
        nw->next = NULL;
        if (head == NULL) {
            head = nw;
        } else {
            lst->next = nw;
        }
        lst = nw;
        
        printf("To continue(1/0): ");
        scanf("%d", &ans);
    } while (ans != 0);
    
    return head;
}

void display(sl* head) {
    sl* temp = head;
    while (temp != NULL) {
        printf("\n\tRoll No: %d, Name: %s\n", temp->no, temp->name);
        temp = temp->next;
    }
}

void displayAlternate(sl* head){

    sl* p = head;

    while(p != NULL){
        printf("\n\t Roll no = %d, Name = %s", p->no, p->name);

        if(p->next != NULL)
        p = p->next->next;
        else
        break;
    }
}

void swap(sl* p){

    sl* q;

    while(p != NULL && p->next != NULL){
        q = p->next;
        int temp_no;
        char temp_name[20];

    temp_no = p->no;
    p->no = q->no;
    q->no = temp_no;

    strcpy(temp_name, p->name);
    strcpy(p->name, q->name);
    strcpy(q->name, temp_name);

    p = q->next;
    }
}

void add(sl* p){

    sl* nw, *q = p->next;

    while(p != NULL && p->next != NULL){

        nw = (sl*)malloc(sizeof(sl));
    
        nw-> no = p->no + q->no;
        strcpy(nw -> name, p->name);
        strcat(nw -> name, q -> name);

        nw->next = q->next;
        q->next = nw;
        p = nw->next;

    }
    
}