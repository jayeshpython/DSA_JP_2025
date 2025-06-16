
#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling
    displayTree(root);
    freeTree(root);
    printf("Exiting....");
    return 0;
}