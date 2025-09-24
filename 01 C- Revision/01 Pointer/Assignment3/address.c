
// write a Program to read  array elements and print with addresses.

#include <stdio.h>

int main() {
    int arr[5], i;
    int *ptr = arr;

    printf("Enter elements:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", ptr + i);
    }

    printf("\nElement \tValue \tAddress\n");
    for(i = 0; i < 5; i++) {
        printf("%d \t%d \t%p\n", i, *(ptr + i), (ptr + i));
    }

    return 0;
}
