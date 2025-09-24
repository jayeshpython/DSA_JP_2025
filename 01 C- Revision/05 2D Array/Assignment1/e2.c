
/*

	- Write a C program which allocates 2D array dynamically (N X M).
	- Implement logic to get: 
						- Sum of all elements. 
						- sum of elements from the 2nd column
						- Display left and right diagonals
						- sum of left diagonal
						- sum of right diagonal
						- larger element from left diagonal 
						- smaller element from left diagonal
						- larger element from right diagonal
						- smaller element from right diagonal 
						- Sort the left diagonal
						- sort the right diagonal

*/

#include <stdio.h>
int main(){
		
	int arr[3][3];
	int i,j;
	int sum=0, sum2=0;
	int high,low;
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("Enter the elements [%d][%d]: ", i+1, j+1);
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
		sum += arr[i][i];
	}
	printf("\n Sum of left diagonal elements is: %d", sum);
	
	for(i=0; i<3; i++){
		sum2 += arr[i][2-i];
	}
	printf("\n Sum of right digonal elements is: %d", sum2);
	
	high =0;
	
	for(i=0; i<3; i++){
		if(arr[i][i] > high){
			high = arr[i][i];
		}
	}
	printf("\n The largest element from the left diagonal is: %d", high);
	
	return 0;
}
	