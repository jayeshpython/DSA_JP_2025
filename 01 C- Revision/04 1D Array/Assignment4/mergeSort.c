
/*
- Write a C program which allocates two array dynamically.
	- Implement logic to merge and sort two array. 
*/
/*
#include <stdio.h>
int main(){

    int a[5], b[5], c[20];
    int i = 0, j=0, temp=0;

    printf("Enter the elemrnts for array a: ");
    for(i =0; i<5; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter the elemrnts for array b: ");
     for(i =0; i<5; i++){
        scanf("%d", &b[i]);
    }

    for(i=0; i<5; i++){
        c[i] = a[i];
    }
    for(j=0; j<5; j++){
        c[i+j] = b[j];
    }

    for(i=0; i<10; i++){
		for(int k=i+1; k<10; k++){
			if(c[i] > c[k]){
				temp = c[i];
				c[i] = c[k];
				c[k] = temp;
			}
		}
	}
	printf("Sorted merged array: ");
	for(i =0; i<10; i++){
       printf(" %d", c[i]);
    }

    return 0;
}

*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    int size1, size2, i, j, k, temp;
    int *arr1, *arr2, *mergedArr;
 
    printf("Enter size of first array: ");
    scanf("%d", &size1);
    arr1 = (int*)malloc(size1 * sizeof(int));
  
    printf("Enter elements of first array: ");
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
   
    printf("Enter size of second array: ");
    scanf("%d", &size2);
    arr2 = (int*)malloc(size2 * sizeof(int));
   
    printf("Enter elements of second array: ");
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }
  
    mergedArr = (int*)malloc((size1 + size2) * sizeof(int));
  
    for (i = 0; i < size1; i++) {
        mergedArr[i] = arr1[i];
    }
    for (j = 0; j < size2; j++) {
        mergedArr[size1 + j] = arr2[j];
    }
   
    for (i = 0; i < (size1 + size2) - 1; i++) {
        for (k = i + 1; k < (size1 + size2); k++) {
            if (mergedArr[i] > mergedArr[k]) {
                temp = mergedArr[i];
                mergedArr[i] = mergedArr[k];
                mergedArr[k] = temp;
            }
        }
    }
  
    printf("Sorted merged array: ");
    for (i = 0; i < size1 + size2; i++) {
        printf(" %d", mergedArr[i]);
    }
    printf("\n");
    
  
    free(arr1);
    free(arr2);
    free(mergedArr);
    
    return 0;
}

