
//Write a C program to display element in a BST levelwise

#include <stdio.h>
#include <stdlib.h>

// Define BST Node
typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} node;

// Create a new BST Node
node* createNode(int data) {

    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("\nMemory error.");
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
node* insert(node* root, int data) {

    if (root == NULL)
        return createNode(data); 

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Queue node for Tree node pointer
typedef struct QueueNode {
    node* treeNode;
    struct QueueNode* next;
} QNode;

typedef struct Queue {
    QNode* front, *rear;
} Que;

// Create a Queue
Que* createQueue() {

    Que* q = (Que*)malloc(sizeof(Que));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Que* q, node* treeNode) {

    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->treeNode = treeNode;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

node* dequeue(Que* q) {

    if (q->front == NULL)
        return NULL;

    QNode* temp = q->front;
    node* n = temp->treeNode;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return n;
}

int isQueueEmpty(Que* q) {
    return q->front == NULL;
}

// Level Order Traversal
void levelOrderTraversal(node* root) {

    if (root == NULL)
        return;

    Que* q = createQueue();
    enqueue(q, root); 

    while (!isQueueEmpty(q)) {

        node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left)
            enqueue(q, current->left);
        if (current->right)
            enqueue(q, current->right);
    }

    free(q);
}

// Main Function
int main() {
    
    node* root = NULL;
    int n, value;

    printf("\nEnter number of elements to insert in BST: ");
    scanf("%d", &n);
    printf("Enter %d values: \n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nLevel Order Traversal of BST: ");
    levelOrderTraversal(root);

    return 0;
}

