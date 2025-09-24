
//write C program to find the HCF (Highest Common Factor) of a numbers using recursion

#include <stdio.h>

int hcfOfTwoNumbers(int , int, int);

int main(){

    int a,b, hcf;
    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter number two: ");
    scanf("%d", &b);

    hcf = hcfOfTwoNumbers(a,b,1);
    printf("\nThe HCF of two numbers is: %d", hcf);

    return 0;
}

int hcfOfTwoNumbers(int a, int b, int k){

    int max;
    if(k > a || k > b)
        return 0;

    max = hcfOfTwoNumbers(a, b, k+1);

    if(a %k == 0 && b %k == 0){
        printf("%d ", k);

        if(max < k)
        max = k;
    }
    return max;
}