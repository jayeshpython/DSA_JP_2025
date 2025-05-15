

#include<stdio.h>

void InsertionSort(int*a,int size){

    int i,j,b;
    for(i = 1; i < size; i++){
        b = a[i];
        j = i-1;

        while(j >= 0 && a[j] > b){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = b;
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
    for(int i = 0; i < n;  i++){
        scanf("%d",&arr[i]);
    }

    InsertionSort(arr,n);
    printf("\nSorted Array is:\n");
    DisplayArray(arr,n);
    return 0;
}