

/*
"write a c program to Create and Display Singly Linked list. with structure ""Student"" with following data members:
-Name 
-Roll no
-standard
-Division
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student{
    char name[20];
    int rollNo;
    int std;
    char div;
    struct Student *next;
}stud;

stud* create(stud*);
void display(stud*);

int main(){

    stud  *start = NULL;
    start = create(start);
    display(start);

    return 0;
}

stud* create(stud* head){

    stud* nw, *lst = NULL;
    int ans;

do{
    nw = (stud*)malloc(sizeof(stud));
    printf("Enter Name, Roll no, Standard and Division : ");
    scanf("%s %d %d %c", nw->name, &nw->rollNo, &nw->std, &nw->div);

    nw->next = NULL;

    if(head == NULL){
        head = nw;
    }
    else{
        lst->next = nw;
    }
    lst = nw;

    printf("To continue(1/0): ");
    scanf("%d", &ans);
}while(ans != 0);
    return head;
}

void display(stud* p){

    while(p != NULL ){
        printf("\n\tName: %s, Roll no: %d, Standard: %d, Division: %c\n", p->name, p->rollNo, p->std, p->div);
        p = p->next;
    }
}