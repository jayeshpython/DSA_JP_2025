

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Doubly{
    int no;
    char name[20];
    struct Doubly* next;
    struct Doubly* prev;
}dsl;

dsl* create(dsl*);
void display(dsl*);
void freeList(dsl*);
dsl* deletion(dsl*);

int main(){

    dsl* last = NULL;
    last = create(last);
    display(last);

    printf("\n\tlinked list after deleting node");
    last = deletion(last);
    display(last);
    freeList(last);

    return 0;
}

dsl* create(dsl* last){

    dsl* newNode;
    int ans;

    do{
        newNode = (dsl*)malloc(sizeof(dsl));
        printf("\n\tEnter number and name: ");
        scanf("%d %s", &newNode->no, newNode->name);

        newNode->next = NULL;
        newNode->prev = last;

        if(last == NULL){
            last = newNode;
            last->next = last;
            last->prev = last;
        }
        else{
            newNode->next = last->next;
            last->next->prev = newNode;
            last->next = newNode;
            last = newNode;
        }

        printf("\n\tDo you want to enter more records: ");
        scanf("%d", &ans);
    } while(ans != 0);
    return last;
}

void display(dsl* last){

    if(!last){
        printf("\n\tList is empty");
        return;
    }
    dsl* p =last->next;

    do{
        printf("\n\tNumber = %d, Name = %s", p->no, p->name);
        p = p->next;
    } while(p != last->next);
}

void freeList(dsl* last){

    dsl* temp;
    dsl* p = last->next;

    do{
         temp = p;
        p = p->next;
        free(temp);
    } while(p != last);
    free(last);
    printf("\n\tMemory freed successfully!");
}


dsl* deletion(dsl* last){

	int flag = 0;
	int key;

	if(last == NULL){
		printf("list is empty\n");
		return last;
	}
	printf("Enter key:");
	scanf("%d",&key);

	dsl* p = last->next;
	while(p != last && p->no != key){
		p = p->next;
	}
	if(p->no == key){
		if(p->next == p){
			free(p);
			last = NULL;
			printf("key is deleted succesfully\n");
		}
		else{
			p->prev->next = p->next;
			p->next->prev;
            p->prev;
			free(p);
			printf("key is deleted succesfully\n");

		}
	}
	else{
		printf("key does not exist\n");
	}
	return last;
}
