
//Write a C program to create BST and Display the elements in the BST in PostOrder

#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling

    printf("Displaying tree elements in Postorder: \n");
    postorder(root);           //Function calling

    return 0;
}