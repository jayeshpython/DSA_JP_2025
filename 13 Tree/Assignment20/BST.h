
#include <stdio.h>
#include <stdlib.h>

typedef struct BST{          //Structure Declaration
    int data;
    struct BST *left, *right;
}bst;

//Function declaration
bst* create(bst*);
bst* insert(bst*, bst*);
void display(bst*);
//void validBST(bst*);
