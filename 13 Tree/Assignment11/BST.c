
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

/*
int findMax(const bst* root){

    int max = root->data;
    const bst* p = root;

    while(p != NULL){

        if(p->data > max){
            max = p->data;
        }
        p = p->right;
    }
    return max;
}
*/

int findMax(const bst* root){

    int max = root->data;
    if(root->right != NULL){
        int rightMax = findMax(root->right);

        if(rightMax > max)
            max = rightMax;
    }

    if(root->left != NULL){
        int leftMax = findMax(root->left);

        if(leftMax > max)
            max = leftMax;
    }
    return max;
    
}

