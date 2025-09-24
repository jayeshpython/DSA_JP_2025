
//Write a C program to count the number of leaf and non-leaf nodes.

#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling
    displayTree(root);
    
    int leaf =0, nonLeaf =0;
    countLeafNonLeaf(root, &leaf, &nonLeaf);
    printf("\nLeaf nodes: %d\n, Non leaf nodes: %d", leaf, nonLeaf);
    
    return 0;
}