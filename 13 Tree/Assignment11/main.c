
//Write a C program to find the maximum element in the BST.

#include "BST.h"

int main(){

    bst* root = NULL;
    int ans;

    root = createTree(root);     //Function calling
    displayTree(root);
    
    ans = findMax(root);
    printf("\nMaximum element in tree: %d", ans);
    
    return 0;
}