#include "BST.h"

bst* create(bst* root){

    bst* newNode;
    int ans;

    do{
        newNode = (bst*)malloc(sizeof(bst));
        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->left = newNode->right = NULL;

        root = insert(root, newNode);

        printf("Do you want to enter more records(1/0): ");
        scanf("%d", &ans);

    }while(ans != 0);
    return root;
}

void display(bst* root){

    if(root != NULL){
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

bst* insert(bst* root, bst* newNode){

    if(root == NULL)
        return newNode;

    
    if(root->left == NULL){
        root->left = newNode;
    }

    if(root->right == NULL){
        root->right = newNode;
    }

    else{
    printf("Node is already present.");
    }

    insert(root->left, newNode);
    insert(root->right, newNode);

    return root;
}

int validBST(bst* root){

    if(root != NULL){

        if(root->left->data > root->data || root->right->data < root->data){
            return 0;
        }
        validBST(root->left);
        validBST(root->right);
    }
    return 1;
}

    
