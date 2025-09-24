
//Write a C program to create BST and Search an element in BST using iterative aproach 

#include "BST.h"

int main(){

    int key, ans;
    bst* root = NULL;
    root = createTree(root);     //Function calling
    void displayTree(bst* root);

    printf("Enter element to search: ");
    scanf("%d", &key);

    ans = searchKey(root, key);

    if(ans == 1){
        printf("Key found.");
    }
    else{
        printf("Key not found.");
    }

    return 0;
}