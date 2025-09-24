
//Accept a  number 'N' and calculate the sum  of digits in the number using recursion

#include <stdio.h>

long long int numberOfDigit(long long int);

int main(){
    long long int n, result;
    printf("Enter number: ");
    scanf("%lld", &n);

    result = numberOfDigit(n);
    printf("Sum of digits in number: %lld", result);
    return 0;
}

long long int numberOfDigit(long long int n){

    long long int sum =0, a=0;

    if(n > 0){
        sum = numberOfDigit(n / 10);
        a = n %10;
    }
    
    return (sum + a);
}