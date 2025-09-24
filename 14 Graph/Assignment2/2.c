
//Write a C program to create a Graph using Adjacency List
#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListEdge {
    int no;
    struct AdjListEdge* next;
} edge;

void A_List(edge*, int);
void print(edge*, int);

int main() {
    edge* head = NULL;
    int ver, i, ch;

    printf("Enter the number of vertices: ");
    scanf("%d", &ver);

    head = (edge*)malloc((ver + 1) * sizeof(edge));

    if (head == NULL) {
        printf("\nMemory allocation failed");
        return 1;
    }

    for (i = 1; i <= ver; i++) {
        head[i].no = i;
        head[i].next = NULL;
    }

    do {
        printf("\n**********************");
        printf("\n1. Add edges");
        printf("\n2. Print Adjacency List");
        printf("\n3. Exit");
        printf("\n***********************");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                A_List(head, ver);
                break;

            case 2:
                print(head, ver);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}

void A_List(edge* a, int ver) {
    int i, j;
    edge *nw, *e;

    printf("\nEnter edge (from to): ");
    scanf("%d %d", &i, &j);

    if (i <= ver && j <= ver && i > 0 && j > 0) {
        nw = (edge*)malloc(sizeof(edge));
        nw->no = j;
        nw->next = NULL;

        if (a[i].next == NULL) {
            a[i].next = nw;
        } else {
            for (e = a[i].next; e != NULL; e = e->next) {
                if (e->no == j) {
                    printf("Edge already exists!\n");
                    free(nw);
                    return;
                }
                if (e->next == NULL) {
                    e->next = nw;
                    return;
                }
            }
        }
    } else {
        printf("Invalid edge!\n");
    }
}

void print(edge* a, int ver) {
    int i;
    edge* e;

    for (i = 1; i <= ver; i++) {
        printf("\nVertex %d --> ", a[i].no);
        for (e = a[i].next; e != NULL; e = e->next) {
            printf("%d ", e->no);
        }
    }
    printf("\n");
}
