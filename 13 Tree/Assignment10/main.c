
//Write a C program to create BST and Deallocate memory by freeing all nodes in the BST

#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling
    displayTree(root);
    freeTree(root);
    printf("Exiting....");
    return 0;
}