

#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    int data;
    struct BST* left, *right;
}bst;

bst* create(bst*);
bst* findLCA(bst*, int, int);
void display(bst*);

int main(){

    bst* root = NULL;
    int p,q;
    root = create(root);

    printf("\nDisplaying Tree elements: \n");
    display(root);

    printf("\nEnter two node to find their LCA: ");
    scanf("%d %d", &p, &q);

    bst *lca = findLCA(root, p, q);
    if (lca)
        printf("LCA of %d and %d is: %d\n", p, q, lca->data);
    else
        printf("Nodes not present in the tree.\n");

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
