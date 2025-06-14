

#include <stdio.h>
#include <stdlib.h>

typedef struct BST{          //Structure Declaration
    int data;
    struct BST *left, *right;
}bst;

//Function declaration
bst* createTree(bst*);
void displayTree(bst*);
