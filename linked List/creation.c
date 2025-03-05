

#include <stdio.h>
#include <stdlib.h>

typedef struct singly {
    int no;
    char name[20];
    struct singly *next;
} sl;

sl* create(sl*);
void display(sl*);

int main() {
    sl* start = NULL;
    start = create(start);
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
        printf("Roll No: %d, Name: %s\n", temp->no, temp->name);
        temp = temp->next;
    }
}
