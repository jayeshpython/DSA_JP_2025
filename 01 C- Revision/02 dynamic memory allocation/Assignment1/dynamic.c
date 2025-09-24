
/*
 write a C program to create memory for int, char and float variable at run time.
     - create memory for int, char and float variables at run time using malloc() function
     - and before exiting the program release the memory allocated at run time by using free() function.
*/
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