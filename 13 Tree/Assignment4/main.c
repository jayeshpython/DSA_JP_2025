
//Write a C program to create BST and Display the elements in the BST in PreOrder

#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling

    printf("Displaying tree elements in Preorder: \n");
    preorder(root);           //Function calling

    return 0;
}