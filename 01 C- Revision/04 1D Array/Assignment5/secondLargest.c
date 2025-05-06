

#include <stdio.h>
int main(){
	
	int arr[20];
	int i, size, temp;
	
	printf("Enter the size: ");
	scanf("%d", &size);
	printf("Enter the elements: ");
	
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("The sorted elements are: ");
	 for(i=0; i<size; i++){
		printf(": %d", arr[i]);
    }
	printf("\nThe second largest element is: %d", arr[size -2]);
		
	return 0;
}