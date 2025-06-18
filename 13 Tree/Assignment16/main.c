
#include <stdio.h>
#include "BST.h"

int main() {
    bst* root = NULL;
    int choice, val, count = 0, even = 0, odd = 0;

    do {
        printf("\n*********** BST Operation ***********\n");
        printf("1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n");
        printf("5. Search (Recursive)\n6. Search (Iterative)\n");
        printf("7. Count Nodes\n8. Count Even/Odd\n");
        printf("9. Find Max Element\n10. Find Height\n");
        printf("11. Count Leaf/Non-Leaf Nodes\n12. Print Leaf Nodes\n");
        printf("13. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("Inorder:\n");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder:\n");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder:\n");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter key to search: ");
                scanf("%d", &val);
                if (searchRecursive(root, val))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;

            case 6:
                printf("Enter key to search: ");
                scanf("%d", &val);
                if (searchIterative(root, val))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;

            case 7:
                count = 0;
                countNodes(root, &count);
                printf("Total nodes: %d\n", count);
                break;

            case 8:
                even = odd = 0;
                countEvenOdd(root, &even, &odd);
                printf("Even: %d\nOdd: %d\n", even, odd);
                break;

            case 9:
                printf("Maximum Element: %d\n", findMax(root));
                break;

            case 10:
                printf("Height of BST: %d\n", findHeight(root));
                break;

            case 11: {
                int leaf = 0, nonleaf = 0;
                countLeafNonLeaf(root, &leaf, &nonleaf);
                printf("Leaf Nodes: %d\nNon-Leaf Nodes: %d\n", leaf, nonleaf);
                break;
            }

            case 12:
                printf("Leaf nodes:\n");
                printLeafNodes(root);
                printf("\n");
                break;

            case 13:
                freeTree(root);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(choice != 13);

    return 0;
}
