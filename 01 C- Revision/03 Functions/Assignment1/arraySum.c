
//Write a function to calculate the sum of all elements of an array

#include <stdio.h>
#include <stdlib.h>
int main(){
	
	int *arr;
	int size, sum=0;
	
	int sumOfArray(int*, int*);
	
	printf("Enter the size: ");
	scanf("%d", &size);
	
	arr = (int*)malloc(sizeof(int)*size);
	printf("Enter the elements of array 1: \n");
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	
	sum = sumOfArray(arr, &size);
	printf("The sum of array element is: %d\n", sum);
  
	free(arr);
	return 0;
}

int sumOfArray(int* arr, int* size){
	int sum=0;
	for(int i=0; i<*size; i++){
		sum += arr[i];
	}
	return sum;
}
	
	