

#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling

    printf("Displaying tree elements in Inorder: \n");
    inorder(root);           //Function calling

    return 0;
}