
/*
"write a c program to Create a Singly linked list  and perform menu driven which includes following functions: 
          - create(),
          - Insert(),
          - Delete(),
          - Reverse(),
          - print()"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SNode {
    int no;
    char name[20];
    struct SNode* next;
} SNode;

SNode* create();
SNode* insertList(SNode*);
SNode* deleteNode(SNode*);
SNode* reverseList(SNode*);  
void printList(SNode*);
void freeList(SNode*);

int main() {
    int choice;
    SNode* start = NULL;

    while (1) {
        printf("\n\n\t******* Menu Driven Program - Singly Linked List *******");
        printf("\n\t1. Create List.");
        printf("\n\t2. Insert Node.");
        printf("\n\t3. Delete Node.");
        printf("\n\t4. Reverse List.");
        printf("\n\t5. Print List.");
        printf("\n\t6. Exit.");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = create();
                break;
            case 2:
                start = insertList(start);
                printList(start);
                break;
            case 3:
                
                start = deleteNode(start);
                printList(start);
                break;
            case 4:
                start = reverseList(start);
                printf("\n\tList reversed successfully!");
                printList(start);
                break;
            case 5:
                printList(start);
                break;
            case 6:
                freeList(start);
                exit(0);
            default:
                printf("\n\tInvalid choice! Please try again.");
        }
    }
    return 0;
}

// Create Linked List
SNode* create(){

    SNode* head = NULL;
    SNode* newNode, *tail = NULL;
    int choice;

    do {
        newNode = (SNode*)malloc(sizeof(SNode));
        if(!newNode) {
            printf("\n\tMemory allocation failed!");
            exit(1);
        }

        printf("\n\tEnter number and name: ");
        scanf("%d", &newNode->no);
        scanf("%19s", newNode->name);
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
        } else{
            tail->next = newNode;
        }
        tail = newNode;

        printf("\n\tDo you want to enter more records? (1(yes) / 0(no)): ");
        scanf("%d", &choice);

    } while(choice == 1);

    printList(head);
    return head;
}

// Print Linked List
void printList(SNode* head){
    if (!head) {
        printf("\n\tList is empty.");
        return;
    }
    printf("\n\tSingly Linked List:");
    while (head != NULL){
        printf("\n\tNumber: %d, Name: %s", head->no, head->name);
        head = head->next;
    }
}

// Free Linked List
void freeList(SNode* head){
    SNode* temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

//Insert into linked list
SNode* insertList(SNode* head){

    SNode* newNode, *p = head;
    newNode = (SNode*)malloc(sizeof(SNode));

    if (!newNode) {
        printf("\n\tMemory allocation failed!");
        return head;
    }

    printf("\n\tEnter number and name to insert: ");
    scanf("%d %s", &newNode->no, newNode->name);
    newNode->next = NULL;

    int key;
    printf("\n\tEnter position of node to add: ");
    scanf("%d", &key);

    // Insert at head
    if ( head == NULL) {
        newNode->next = head;
        head = newNode;
        return newNode;
    }

    for (int i = 1; p != NULL && i < key - 1; p = p->next, i++);

    if (p != NULL) {
            newNode->next = p->next;
            p->next = newNode;
    } else {
        printf("\nInvalid position!");
        free(newNode);
    }

    return head;
}

// Delete from Linked List
SNode* deleteNode(SNode* head){

    SNode* temp = head;
    SNode* p = head;
    SNode* q = head->next;
    int pos, flag =0;

    printf("\nEnter position of node to delete: ");
    scanf("%d", &pos);

    if(head == NULL){
        printf("\nList is empty.");
        return head;
    }

    if( pos == 1){
        head = head-> next;
        free(p);
       return head; 
    }

     // Method 1
    for(int i = 2; q != NULL && i <= pos; i++){
        
        if(i == pos){
            p->next = q->next;
            free(q);
            return head;
        }
        p = q;
        q = q->next;
    }
    
    if(p == NULL){
        printf("\nNo node in linked list.");
    }
    return head;
}

// Reverse Linked List
SNode* reverseList(SNode* head) {
    SNode* q = NULL;
    SNode* p = head;
    SNode* next = NULL;

    while (p != NULL) {
        next = p->next;  
        p->next = q; 
        q = p;        
        p = next;       
    }

    return q; 
}

