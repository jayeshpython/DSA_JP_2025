

#include <stdio.h>
int main(){
	
	int arr[4][4];
	int i,j, transpose;
	
	printf("Enter the elements: \n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("[%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\nThe entered matrix is:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
		
			arr[j][i] = arr[i][j];
		}
	}
	
	printf("\nThe transpose of array is:\n ");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d\t", arr[j][i]); 
        }
        printf("\n");
    }
	
	return 0;
}
	