
//Write a C program to create BST and insert an element in the BST using recursion(Call insert function from create function)

#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    int data;
    struct BST* left, *right;
}bst;

bst* create(bst*);
bst* insert(bst*, bst*);
void display(bst*);

int main(){

    bst* root = NULL;
    root = create(root);

    printf("\nDisplaying Tree elements: \n");
    display(root);
    return 0;
}

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

    if(root->data > newNode->data){
        if(root->left == NULL)
            root->left = newNode;
        else
            insert(root->left, newNode);
    }
    
    else if(root->data < newNode->data){
        if(root->right == NULL)
            root->right = newNode;
        else
            insert(root->right, newNode);
    }
    else{
        printf("Node is already present.");
        free(newNode);
    }
    return root;
}