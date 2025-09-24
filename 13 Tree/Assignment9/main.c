
//Write a C program to create BST and Count Odd and even elements in the BST

#include "BST.h"

int main(){

    int even =0, odd =0;
    bst* root = NULL;
    root = createTree(root);     //Function calling
    void displayTree(bst* root);

    countEvenOddNodes(root, &even, &odd);
    printf("\nEven = %d\n, Odd = %d", even, odd);
    return 0;
}