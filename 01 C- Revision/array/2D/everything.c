



#include <stdio.h>
int main(){
		
	int arr[3][3];
	int i,j;
	int sum=0, sum2=0;

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("Enter the elements [%d][%d]: ", i+1, j+1);
			scanf("%d", &arr[i][j]);
		}
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			sum += arr[i][j];
		}
	}
	printf("\n The sum of all ekements: %d", sum);
	
	for(int i=0; i<3; i++){
		sum2 += arr[i][2];
	}
	printf("\n The sum of elements from the 2nd column: %d\n", sum2);
	
	for(i=0; i<3; i++){
		printf("\n Left diagonal elements are: %d", arr[i][i]);
	}
	
	
	for(i=0; i<3; i++){
		printf("\n Right diagonal elements are: %d", arr[i][2-i]);
	}
	
	return 0;
}
