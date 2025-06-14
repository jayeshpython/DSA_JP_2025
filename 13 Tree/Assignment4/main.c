
#include "BST.h"

int main(){

    bst* root = NULL;
    root = createTree(root);     //Function calling

    printf("Displaying tree elements in Preorder: \n");
    preorder(root);           //Function calling

    return 0;
}