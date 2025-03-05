
#include <stdio.h>
int main(){
	
	int arr[20];
	int size,key,flag;
	
	printf("Enter the size: ");
	scanf("%d", &size);
	printf("Enter the elements: ");
	
	for(int i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Enter the key element to find: ");
	scanf("%d", &key);
	
    for(int i=0; i<5; i++){
        if(key == arr[i]){
            flag = 1;
            break;
        }
    }
        if(flag == 1)
            printf("The key element: %d\n", key);
        
        else
            printf("The element is not present in the array.\n");
     
	return 0;
}
			