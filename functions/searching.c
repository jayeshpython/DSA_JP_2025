

#include <stdio.h>
#include <stdlib.h>
int main(){
	
	void search(int *, int);
	int *arr, size, i=0;
	
	printf("Enter the size: ");
	scanf("%d", &size);
	
	arr = (int*)malloc(sizeof(int)* size);
	printf("Enter the elements: ");
	
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	
	search(arr, size);
	return 0;
}

	void search(int *arr, int size){
		
		int flag=0, key=4;
		
		for(int i=0; i<size; i++){
			if(arr[i] == key){
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			printf("Key element: %d", key);
		else
			printf("Not found");
	}