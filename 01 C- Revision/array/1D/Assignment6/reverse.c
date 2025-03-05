
	
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
	int size,i, temp;

    printf("Enter the size: ");
    scanf("%d", &size);

    arr = (int*)malloc(sizeof(int) * size);

    printf("Enter the elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (i=0; i <size/ 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }

    printf("Reversed array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
