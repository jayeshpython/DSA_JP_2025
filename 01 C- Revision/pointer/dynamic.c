
#include <stdio.h>
#include <stdlib.h>

int main() {
 
    int *arr;
	int sum=0, size;
	
	printf("Enter the size: ");
	scanf("%d", &size);
	
	arr = (int*)malloc(sizeof(int)* size);
	printf("Enter the element: ");
	
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<size; i++){
		printf("\nThe elements are: %d", arr[i]);
	}
	for(int i=0; i<size; i++){
		sum += arr[i];
	}
	printf("\nThe sum of all elements: %d", sum);
	
	return 0;
}