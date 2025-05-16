

#include <stdio.h>

void ExchangeSort(int arr[], int n){

    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = i + 1; j < n; j++){
            if (arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void DisplayArray(int arr[], int n){

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    ExchangeSort(arr, n);
    printf("Sorted array: ");
    DisplayArray(arr, n);

    printf("\nThe Time Complexity of Exchange Sort: O(n^2)");

    return 0;
}
