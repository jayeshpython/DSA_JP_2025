
//Write a C program to print all nodes in a given range [k1,k2]

#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    int data;
    struct BST* left, *right;
}bst;

bst* create(bst*);
void printInRange(bst*, int, int);
void display(bst*);

int main(){

    bst* root = NULL;
    int k1,k2;
    root = create(root);

    printf("\nDisplaying Tree elements: \n");
    display(root);

    printf("Enter range [k1 k2]: ");
    scanf("%d %d", &k1, &k2);

    printf("Nodes in range [%d, %d]: ", k1, k2);
    printInRange(root, k1, k2);
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

void printInRange(bst* root, int k1, int k2){

    if(root != NULL){

        printInRange(root->left , k1, k2);
        if(k1 == root->data || k2 == root->data)
            printf("%d ", root->data);
        if(root->data > k1 && root->data < k2)
            printf("%d ", root->data);
        if(root->data < k1 && root->data > k2)
            printf("%d ", root->data);

        printInRange(root->right, k1, k2);
    }
}