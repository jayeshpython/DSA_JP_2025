
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