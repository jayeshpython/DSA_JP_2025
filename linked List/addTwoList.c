

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singly{
    int no;
    char name[20];
    struct singly* next;
}sl;

sl* create(sl*);
sl* add(sl*);
sl* display(sl*);

int main(){

    sl* start = NULL;
    start = create(start);
    add(start);
    display(start);
    return 0;
}

sl* create(sl* head){

    sl* nw, *lst = NULL;
    int ans;

    do{
        nw = (sl*)malloc(sizeof(sl));
        printf("Enter Roll no and Nane: ");
        scanf("%d %s", &nw->no, nw->name);

        nw->next = NULL;
        if(head == NULL)
        head = nw;

        else
        lst->next = nw;

        lst = nw;

        printf("To continue (1/0): ");
        scanf("%d", &ans);
    }while(ans != 0);
    return head;
}

sl* add(sl* p){

    while(p != NULL && p->next != NULL){

        sl* nw, *q;
        q = p->next;
        nw = (sl*)malloc(sizeof(sl));

        int new_no = p->no + q->no;
        strcpy(nw -> name, p->name);
        strcat(nw -> name, q -> name);

        nw -> next = q -> next;
        q ->next = nw;
        p = nw->next;
    }
}

sl* display(sl* p){
    printf("\nList details");
    for( ; p != NULL; p = p->next){
        printf("\tNumber = %d, Name = %s", p->no, p->name);
    }
}

