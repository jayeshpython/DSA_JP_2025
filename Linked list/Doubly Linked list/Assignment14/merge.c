
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNode{
    int no;
    char name[20];
    struct DNode* prev;
    struct DNode* next;
}

DNode* create(DNode*);
void displayu(DNode*);

int main(){

    DNode* start = NULL;
    start = create(NULL);
    display(start);

    printf("\n\tLinked list after mergeing two linked list.");

    return 0;
}

DNode* create(DNode* head){

    
}