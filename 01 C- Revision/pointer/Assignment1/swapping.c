
#include <stdio.h>
int main(){
    int a,b;
    void swap(int* ,int*);

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    swap(&a, &b);
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("a = %d, b = %d", *a,*b);
}