


#include <stdio.h>
int main(){
		
	int arr[3][3];
	int i,j;
	int high,low;
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("Enter the elements [%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\nThe entered matrix is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
	
	high = low = arr[0][2];
	for(i=0; i<3; i++){
		if(arr[i][2-i] < low){
			low = arr[i][2-i];
		}
	}
	printf("\n The smallest element from right diagonal is: %d", low);
	
	for(i =0; i<3; i++){
		if(arr[i][2-i] > high){
			high = arr[i][2-i];
		}
	}
	printf("\n The largest element from right diagonal is: %d", high);
	
	return 0;
}