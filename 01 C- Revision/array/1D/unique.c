

#include <stdio.h>
#include <stdlib.h>

int main() {
  
    int *arr;
    int size, i, j, num, unique;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    for (i = 0; i < size; i++) {
        while (1) {  
            printf("Enter a unique number: ");
            scanf("%d", &num);
            
            unique = 1;
            for (j = 0; j < i; j++) {
                if (arr[j] == num) {
                    unique = 0;
                    printf("Duplicate! Try again.\n");
                    break;
                }
            }
            
            if (unique) {
                arr[i] = num;
                break; 
            }
        }
    }
    
    printf("Unique elements in array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}
