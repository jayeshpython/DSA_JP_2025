
/*
- Write a C program which allocates an array dynamically.
	- Implement logic to check the frequency of each element throughout the array
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	
	int *arr;
	int size, cnt;
	
	printf("Enter the size: ");
	scanf("%d", &size);
	
	arr = (int*)malloc(sizeof(int)* size);
	printf("\nEnter the elements: ");
	
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i=0; i<size; i++){
		cnt = 1;
		if(arr[i] != -1){
				
			for(int j=i+1; j<size; j++){
				if(arr[i] == arr[j]){
					cnt++;
					arr[j] = -1;
				}
			}
			printf("\n %d occurs %d times\n", arr[i], cnt); 
		}
	}
	free(arr);
	return 0;
}
		