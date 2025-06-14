
#include "BST.h"

bst* createTree(bst* root){

    bst* newNode, *temp;
    int ans;

    do{
        newNode = (bst*)malloc(sizeof(bst));
        if(!newNode){
            printf("Memory allocation  failed.");
            return NULL;
        }

        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->left = newNode->right = NULL;

        if(root == NULL){
            root = newNode;
        }
        else{
            temp = root;
            while(1){
                if(newNode->data < temp->data){
                    if(temp->left == NULL){
                        temp->left = newNode;
                        break;
                    }
                    temp = temp->left;
                }
                else if(newNode->data > temp->data){
                    if(temp->right == NULL){
                        temp->right = newNode;
                        break;
                    }
                    temp = temp->right;
                }
                else{
                    printf("Node is already present.");
                    free(newNode);
                    break;
                }
            }
        }
        printf("Do you want to enter more records(1/0): ");
        scanf("%d", &ans);

    }while(ans != 0);
    return root;
}

void displayTree(bst* root){

    if(root != NULL){
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}

int searchKey(bst* root, int key){

    if(!root){
        printf("Tree is empty.");
        return 0;
    }

    if(root == NULL)
    return 0;

    if(root->data == key)
    return 1;

    if(key < root->data)
    return searchKey(root->left, key);

    return searchKey(root->right, key);
}