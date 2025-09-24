
//Accept n elements in an array and display the differance between the sum of 1st half  and 2nd half of that array                                       

#include <stdio.h>
int main(){
	int arr[20];
	int sum=0, diff=0, size;
	int sum1=0, sum2=0;
	
	printf("Enter the size: ");
	scanf("%d", &size);
	printf("\nEnter the elements: ");
	
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<size; i++){
		if(i < size/2){
			sum1 += arr[i];
		}
		else{
			sum2 += arr[i];
		}
	}
	sum = sum1 + sum2;
	diff = sum1 - sum2;
	
	printf("\nThe sum of 1st half of array: %d", sum1);
	printf("\nThe sum of 2nd half of array: %d", sum2);
	printf("\nThe sum of all elements of array is: %d", sum);
	printf("\nThe sum of difference between the 1st half and 2nd half of array: %d", diff);
	
	return 0;
}
	
	