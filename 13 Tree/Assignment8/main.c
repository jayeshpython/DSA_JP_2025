
#include "BST.h"

int main(){

    int ans;
    bst* root = NULL;
    root = createTree(root);     //Function calling
    void displayTree(bst* root);

    ans = countNodes(root);
    printf("\nNumber of nodes in Tree: %d", ans);
    return 0;
}