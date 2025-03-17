

#include <stdio.h>
int main(){
	
	int arr[20];
	int *ptr;
	int flag=0, key=2;
	
	ptr = arr;
	
	printf("Enter the elements: ");
	for(int i=0; i<10; i++){
		scanf("%d", (ptr+i));
	}
	
	for(int i=0; i<10; i++){
		if(key == *(ptr+i)){
			flag = 1;
			break;
		}
	}
	if(flag == 1)
		printf("The key element is : %d", key);
	else
		printf("Element is not present:");
	
	return 0;
}
	
	