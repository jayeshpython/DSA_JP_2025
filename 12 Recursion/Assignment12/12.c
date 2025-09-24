
//accept two numbers and find the GCD of the numbers  using recursion

#include <stdio.h>

int gcdOfTwoNumbers(int , int, int);

int main(){

    int a,b, gcd;
    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter number two: ");
    scanf("%d", &b);

    gcd = gcdOfTwoNumbers(a,b,1);
    printf("\nThe GCD of two numbers is: %d", gcd);

    return 0;
}

int gcdOfTwoNumbers(int a, int b, int k){

    int max;
    if(k > a || k > b)
        return 0;

    max = gcdOfTwoNumbers(a, b, k+1);

    if(a %k == 0 && b %k == 0){
        printf("%d ", k);

        if(max < k)
        max = k;
    }
    return max;
}