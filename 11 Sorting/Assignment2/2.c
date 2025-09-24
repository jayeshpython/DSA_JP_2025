
//Write a C program to Accept an array and Perform Bubble sort.

#include <stdio.h>

void bubbleSort(int arr[], int n){

    int temp = 0, swapped = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j <n-1-i; j++){

            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0)
        break;
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
    scanf("%d",&n);

    int arr[n];

    printf("\nEnter the elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr,n);
    printf("\nSorted Array is:\n");
    DisplayArray(arr,n);

    printf("\nTime Complexity of Bubble Sort:");
    printf("\nBest Case: O(n)");
    printf("\nAverage Case: O(n^2)");

    return 0;
}