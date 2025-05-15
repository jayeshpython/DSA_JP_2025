

#include <stdio.h>

int linearSearch(int arr[], int key, int n){

    int i;
    for(i = 0; i<10; i++){
        if(arr[i] == key){
            return 1;
        }
    }
    return 0;
}

int main(){

    int arr[10], key;

    printf("Enter 10 elements: ");
    for(int i = 0; i<10; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nEnter key element: ");
    scanf("%d", &key);

    int result = linearSearch(arr, key, 10);

    if(result)
    printf("\nKey found.");
    else
    printf("\nKey not found");

    printf("\nTime Complexity of Linear Search: O(n)");

    return 0;
}