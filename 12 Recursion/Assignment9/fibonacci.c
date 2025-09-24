
//write a C Program to print Fibonacci series using Recursion

#include <stdio.h>

void fibonacciSeries(int, int, int );

int main(){

    int a = 0, b = 1, n;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("Fibonacci Series: \n");
    fibonacciSeries(a,b, n);
    return 0;
}

void fibonacciSeries(int a, int b, int n){

    int sum = a+b;
    if(a <= n){

        printf("%d ", a);
        fibonacciSeries(b, sum, n);
    }
}