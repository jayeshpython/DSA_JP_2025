

#include<stdio.h>

void selectionSort(int a[],int size){

    int i,j,low,temp;

    for(i = 0; i < size-1; i++){
        low = i;
        for(j = i+1; j < size; j++){
            if(a[j] < a[low])
              low = j;
        }
        if(low != i){
            temp = a[low];
            a[low] = a[i];
            a[i] = temp;
        }
    }
}

void DisplayArray(int arr[],int n){

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){

    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    selectionSort(arr,n);
    printf("\nSorted Array is:\n");
    DisplayArray(arr,n);

    printf("\n\nTime Complexity of Selection Sort: O(n^2)");
   
    return 0;
}