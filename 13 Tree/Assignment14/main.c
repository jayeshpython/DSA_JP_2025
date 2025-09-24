
//Write a C program to print all leaf nodes of the BST.

#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling
    displayTree(root);
    
    printf("\nLeaf nodes of tree: \n");
    printLeafNodes(root);
    return 0;
}