
//Write a C program to create BST and Display the elements in the BST in InOrder

#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling

    printf("Displaying tree elements in Inorder: \n");
    inorder(root);           //Function calling

    return 0;
}