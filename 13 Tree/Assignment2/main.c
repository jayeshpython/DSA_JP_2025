
//Write a C program to create BST and insert an element in the BST

#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling

    printf("Inserting new element to tree: \n");
    root = insert(root);
    displayTree(root);           //Function calling

    return 0;
}