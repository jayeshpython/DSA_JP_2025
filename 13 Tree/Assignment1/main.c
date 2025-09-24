
//Write a C program to create BST (Binary Search Tree)

#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling

    printf("Displaying tree elements: \n");
    displayTree(root);           //Function calling

    return 0;
}