
#ifndef BST_H
#define BST_H

typedef struct BST{
    int data;
    struct BST* left, *right;
}bst;

bst* insert(bst*, int data);
void inorder(const bst* root);
void preorder(const bst* root);
void postorder(const bst* root);
int searchRecursive(const bst* root, int key);
int searchIterative(const bst* root, int key);
void countNodes(const bst* root, int *count);
void countEvenOdd(const bst* root, int* even, int* odd);
void freeTree(bst* root);
int findMax(const bst* root);
int findHeight(const bst* root);
void countLeafNonLeaf(const bst* root, int* leaf, int* nonleaf);
void printLeafNodes(const bst* root);
#endif