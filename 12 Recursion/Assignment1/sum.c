
//Accept  N  numbers and calculate sum of all numbers using recursion

#include <stdio.h>

int sumOfNumbers(int[], int);

int main(){
    int n, result;
    printf("Enter the size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    result = sumOfNumbers(arr, n);
    printf("The sum of n numbers is: %d", result);
    return 0;
}

int sumOfNumbers(int arr[], int n){
    int sum = 0;

    for(int i = n; i != 0; i--){
        if(n != 0){
            sum = sumOfNumbers(arr, n-1);
        }
    }
    return (sum+n);
}
