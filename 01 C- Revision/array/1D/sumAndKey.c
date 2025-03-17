
#include <stdio.h>
int main(){

    int arr[5];
    int sum=0, flag=0 ,key, temp=0;
    int i=0;

    printf("Enter the element: ");
    for(i =0; i<5; i++){
        scanf("%d", &arr[i]);
    }

    for(i=0; i<5; i++){
        sum += arr[i];
    }
     printf("Sum of elements is: %d", sum);

    printf("\nEnter the element to find: ");
    scanf("%d", &key);

    for(i=0; i<5; i++){
        if(key == arr[i]){
            flag = 1;
            break;
        }
    }
        if(flag == 1)
            printf("The key element: %d\n", key);
        
        else
            printf("The element is not present in the array.\n");
        

    for(i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j]; 
                arr[j] = temp;
            }
        }
	}
	
     printf("The sorted elements are: ");
	 for(i=0; i<5; i++){
		printf(": %d", arr[i]);
    }
    
    return 0;

    }
