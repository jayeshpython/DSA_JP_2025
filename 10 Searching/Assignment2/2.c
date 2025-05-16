
#include <stdio.h>

int binarySearch(int arr[], int n, int key){

    int low = 0, high = n-1, mid;

    while(low <= high){
        mid = (low + high)/2;

        if(arr[mid] == key)
        return mid;

        else if(arr[mid] < key)
        low = mid + 1;
        else
        high = mid - 1;
    }
    return -1;
}

int main(){

    int n,key,ans;

    printf("\nEnter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter elements: ");
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("\n\tEnter key: ");
    scanf("%d", &key);

    ans = binarySearch(arr, n, key);

    if(ans != -1)
    printf("\nKey found at %d", ans);
    else
    printf("\nKey not found");

    printf("\nTime Complexity of Binary Search: O(logn)");
    return 0;
}