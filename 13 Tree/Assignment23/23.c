
//Write a C program to Print path from root to given node [target node]

#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    int data;
    struct BST* left, *right;
}bst;

bst* create(bst*);
void printPath(bst*, int);
void display(bst*);

int main(){

    bst* root = NULL;
    int target;
    root = create(root);

    printf("\nDisplaying Tree elements: \n");
    display(root);

    printf("\nEnter target node value: ");
    scanf("%d", &target);
    printPath(root, target);

    return 0;
}

bst* create(bst* root){

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

void display(bst* root){

    if(root != NULL){
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

/*
void printPath(bst* root, int target){

    bst* temp = root;
    while(temp != NULL){
        if(temp->data > target){
            printf("%d ", temp->data);
            temp = temp->left;
        }
        if(temp->data < target){
            printf("%d ", temp->data);
            temp = temp->right;
        }
        if(temp->data == target){
            printf("%d ", temp->data);
            break;
        }
    }
}
*/


void printPath(bst* root, int target){

    if (root == NULL) {
        printf("Target not found in the tree.\n");
        return;
    }

    printf("%d ", root->data); 

    if (root->data == target) {
        printf("\n");
        return;
    }
    else if(target < root->data)
        printPath(root->left, target);
    else 
        printPath(root->right, target);
}
