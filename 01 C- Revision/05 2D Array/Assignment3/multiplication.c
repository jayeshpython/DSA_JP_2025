
//Accept elements in two n*m matrix and display the multiplication of two matrix

#include <stdio.h>
int main(){
	
	int a[3][3], b[3][3], c[3][3];
	int i,j;
	
	printf("Enter the elements of array a\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	printf("Enter the elements of array b\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("[%d][%d]: ", i, j);
			scanf("%d", &b[i][j]);
		}
	}
	
	printf("\nThe entered matrix a is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
	printf("\nThe entered matri b is:\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}
	// multiplication of two matrix
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			c[i][j] = 0;
			for(int k=0; k<3; k++){	
			c[i][j] += a[i][k] * b[k][j];
		}
	}
	}
	printf("\nThe matrix c is:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
	
	return 0;
}