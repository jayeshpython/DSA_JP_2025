
//accept an array and display the array in reverse order using recursion

#include <stdio.h>
#include <stdlib.h>

void reverseArray(int arr[], int n){

    if(n == 0)
    return;

    printf("%d ", arr[n - 1]);
    reverseArray(arr, n-1);
}

int main(){

    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Reversed array using recursion: \n");
    reverseArray(arr, n);
    return 0;
}
