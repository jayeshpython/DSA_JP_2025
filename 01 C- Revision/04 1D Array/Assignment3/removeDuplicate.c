
/*
- Write a C program which allocates an array dynamically.
	- Implement logic that removes duplicate elements from the array. 
*/

/*
#include <stdio.h>
int main(){

    int arr[7];
    int cnt=0, flag;
	int i;
    printf("Enter the elemrnts: ");
    
    for(int i =0; i<7; i++){
        scanf("%d", &arr[i]);
    }

      for(int i=0; i<7; i++){
			cnt = 1;
			
			for(int j=0; j<7; j++){
				if(arr[i] == arr[j]){
					break;
				}
			}
	  
	  if(cnt == 1)
		  printf("Removed elements: %d", arr[i]);
	  }
	  return 0;

	  }		
				
*/


#include <stdio.h>
int main(){

	int arr[9];
	int i, j, temp,size;

	printf("\n\tEnter the size: ");
	scanf("%d", &size);

	printf("\n\tEnter the elements: ");
	for(int i = 0; i<size; i++){
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
	printf("Removed duplicate elements are\n"); 
    for (int i=0; i<size; i++) {
        if (arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}