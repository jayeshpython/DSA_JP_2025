
#include <stdio.h>
int main(){

    int arr[7];
    int high =0, low =0;
    int sum = 0, diff =0;
    int i = 0;

    printf("Enter the elemrnts: ");
    
    for(i =0; i<7; i++){
        scanf("%d", &arr[i]);
    }
	
	high = low = arr[0];
	
    for(i=0; i<7; i++){
        if(arr[i] > high){
            high = arr[i];
        }
      
        if(arr[i] < low){
            low = arr[i];
        }
	}
        sum = high + low;
        diff = high - low;

		printf("Highest element is: %d\n", high);
		printf("Lowest element is: %d\n", low);
		printf("Sum of highest and lowest is: %d\n", sum);
        printf("Difference of highest and lowest is: %d\n", diff);
        return 0;
    }
    

