
//"Write a C program to calculate the height (depth) of the BST.
//The depth of a node is the number of edges present in path from the root node of a tree to that node."

#include "BST.h"

int main(){

    int height;
    bst* root = NULL;

    root = createTree(root);     //Function calling
    displayTree(root);

    height = findHeight(root);
    printf("\nThe height of tree is: %d", height);
    return 0;
}