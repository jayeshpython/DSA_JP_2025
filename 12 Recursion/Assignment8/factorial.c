
#include <stdio.h>

int factorial(int n){

    int result =1;
    if(n != 1){
        result = factorial(n-1);
    }
    return (result *n);
}

int main(){

    int n, result;
    printf("Enter number: ");
    scanf("%d", &n);

    result = factorial(n);
    printf("Factorial = %d", result);
    return 0;
}