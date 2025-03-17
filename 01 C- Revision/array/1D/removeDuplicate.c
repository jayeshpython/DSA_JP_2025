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

	int arr[9] = {1,2,4,1,3,2,5,4,2};
	int i, j, temp;
	
	for(int i=0; i<9; i++){
		for(int j=i+1; j<9; j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("Removed duplicate elements are\n"); 
    for (int i=0; i<9; i++) {
        if (arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}