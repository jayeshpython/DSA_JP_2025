
//Write a C program to display element in a BST levelwise

#include "BST.h"

int main(){

    bst* root = NULL;
    root = create(root);     //Function calling
    display(root);
    //validBST(root);
    return 0;
}