

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char name[20];
    int no;
    struct Node* next;
} Node;

Node* create();
void display(Node*);
void freeList(Node*);

int main() {
    Node* start = NULL;
    start = create();
    
    printf("\nLinked List:\n");
    display(start);
    freeList(start);
    return 0;
}

Node* create() {

    Node* nw;
    int ans;
    nw = (Node*)malloc(sizeof(Node));

    if (nw == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    printf("Enter name and number: ");
    scanf("%s %d", nw->name, &nw->no);
    nw->next = NULL;

    printf("To continue(1/0): ");
    scanf("%d", &ans);
    
    if (ans != 0) {
        nw->next = create();
    }
    return nw;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Number: %d\n", temp->name, temp->no);
        temp = temp->next;
    }
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
