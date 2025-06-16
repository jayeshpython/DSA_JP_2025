
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

int findHeight(const bst* root){

    int leftCnt = 0, rightCnt =0;

    if(root != NULL){

        leftCnt = findHeight(root->left);
        rightCnt = findHeight(root->right);
    
        if(leftCnt > rightCnt)
            return leftCnt +1;
        else
            return rightCnt +1;
    }
    return 0;
}