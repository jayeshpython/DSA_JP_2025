

#include <stdio.h>
#include <stdlib.h>
int main(){
	
	int *arr1, *arr2, *arr3;
	int size;
	
	int* sum(int* , int*, int);
	printf("Enter the size: ");
	scanf("%d", &size);
	
	arr1 = (int*)malloc(sizeof(int)*size);
	arr2 = (int*)malloc(sizeof(int)*size);
	arr3 = (int*)malloc(sizeof(int)*size);
	
	printf("Enter the elements of array 1: \n");
	for(int i=0; i<size; i++){
		scanf("%d", &arr1[i]);
	}
	
	printf("Enter the elements of array 2: \n");
	for(int i=0; i<size; i++){
		scanf("%d", &arr2[i]);
	}
	
	arr3 = sum(arr1, arr2, size);
	
	printf("The sum of two arrays is: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

	free(arr1);
    free(arr2);
    free(arr3);
	return 0;
}

int* sum(int* arr1, int* arr2, int size){
	
	int *arr3;
	arr3 = (int*)malloc(sizeof(int)*size);
		
		for(int i=0; i<size; i++){
			arr3[i] = arr1[i] + arr2[i];
		}
		return arr3;
}

