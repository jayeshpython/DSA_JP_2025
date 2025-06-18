
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

bst* insert(bst* root, int data){

    if(root == NULL){
        bst* newNode = (bst*)malloc(sizeof(bst));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if(data < root->data)
    root->left = insert(root->left, data);

    else if(data > root->data)
    root->right = insert(root->right, data);

    return root;
}

void inorder(const bst* root){
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(const bst* root){
    if(root){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(const bst* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int searchRecursive(const bst* root, int key){

    if(root == NULL)
        return 0;

    if(root->data == key)
        return 1;

    if(key < root->data)
        return searchRecursive(root->left, key);

    return searchRecursive(root->right, key);
}

int searchIterative(const bst* root, int key){

    const bst* p = root;
    while(p != NULL){
        if(p->data == key)
            return 1;

        if(p->data > key)
        p = p->left;
        else
        p = p->right;
    }
    return 0;
}

void countNodes(const bst* root, int* count){

    if(root){
        (*count)++;
        countNodes(root->left, count);
        countNodes(root->right, count);
    }
}

void countEvenOdd(const bst* root, int* even, int* odd){

    if(root){

        if(root->data %2 == 0)
            (*even)++;
        else
            (*odd)++;

        countEvenOdd(root->left, even, odd);
        countEvenOdd(root->right, even, odd);
    }
}

void freeTree(bst* root){

    if(root){
        free(root->left);
        free(root->right);
        free(root);
    }
}

int findMax(const bst* root){

    int max = root->data;
    if(root->right != NULL){
        int rightMax = findMax(root->right);

        if(rightMax > max)
            max = rightMax;
   }
   
    if(root->left != NULL){
        int  leftMax = findHeight(root->left);

        if(leftMax > max)
            max = leftMax;
    }
    return max;
}

int findHeight(const bst* root){

    int leftCnt =0, rightCnt =0;

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

void  countLeafNonLeaf(const bst* root, int* leaf, int* nonleaf){

    if(root != NULL){
        if(root->right == NULL && root->left == NULL)
            (*leaf)++;
        else
            (*nonleaf)++;

        countLeafNonLeaf(root->left, leaf, nonleaf);
        countLeafNonLeaf(root->right, leaf, nonleaf);
    }
}

void printLeafNodes(const bst* root){

    if(root != NULL){
        if(root->left == NULL && root->right == NULL)
            printf("%d ", root->data);

        printLeafNodes(root->left);
        printLeafNodes(root->right);
    }
}