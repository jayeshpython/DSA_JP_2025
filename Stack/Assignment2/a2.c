

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    int no;
    char name[20];
    struct Stack* next;
}stk;

stk* push(stk*);
stk* pop(stk*);
void display(stk*);

int main(){

    stk* top = NULL;
    top = push(top);
    display(top);

    top = pop(top);
    display(top);
    return 0;
}

stk* push(stk* top){

    stk* nw = (stk*)malloc(sizeof(stk));

    if(!nw){
        printf("\n\tMemory allocation failed");
        return NULL;
    }
    printf("\n\tEnter number and name: ");
    scanf("%d %s", &nw->no, nw->name);

    nw->next = top;
    return nw;
}

stk* pop(stk* top){

    if(top == NULL){
        printf("\n\tStack is empty.");
        return NULL;
    }

    stk* p = top->next;
    printf("\n\t%d (%s) is popped", top->no, top->name);
    free(top);

    return p;
}

void display(stk* p){

    if(p == NULL){
        printf("\n\tStack is empty.");
        return ;
    }

    else{
        printf("\n\tStack element,");

        for( ; p != NULL; p = p->next){
            printf("\n\tNumber = %d, Name = %s", p->no, p->name);
        }
    }
}