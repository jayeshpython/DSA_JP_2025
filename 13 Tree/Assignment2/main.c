

#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling

    printf("Inserting new element to tree: \n");
    root = insert(root);
    displayTree(root);           //Function calling

    return 0;
}