

#include <stdio.h>
int main(){
	int arr[3][3];
	int i,j,temp;
	
	printf("Enter the elements: \n");
	for(i=0; i<3;i++){
		for(j=0; j<3; j++){
			printf("[%d][%d]: ", i, j);
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
	for(i=0; i<3; i++){
		for(j=0; j<3-i; j++){
			if(arr[j][j] > arr[j+1][j+1]){
				temp = arr[j][j];
				arr[j][j] = arr[j+1][j+1];
				arr[j+1][j+1] = temp;
			}
		}
	}
	printf("The sorted left diagonal is:\n ");
	 for(i=0; i<3; i++){
		for(j=0; j<3; j++){
		printf(": %d\t", arr[i][j]);
		}
		printf("\n");
	 }
return 0;
}	
				
				
	
		