
#include <stdio.h>

int factorial(int n){

    if(n == 0 || n== 1){
        return 1;
    }
    return factorial(n-1) *n;
}

int main(){

    int n, result;
    printf("Enter number: ");
    scanf("%d", &n);

    result = factorial(n);
    printf("Factorial = %d", result);
    return 0;
}