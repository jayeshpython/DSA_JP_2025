
#include <stdio.h>

long long int reverseIntegerNumber(long long int);
long long int numberOfDigits(long long int);
long long int multiply(long long int);

int main(){

    long long int number, result;
    printf("Enter number: ");
    scanf("%lldd", &number);

    result = reverseIntegerNumber(number);
    if(result == number){
        printf("Number is pallindrome");
    }
    else
    printf("Number is not pallindrome");

    return 0;
}

long long int reverseIntegerNumber(long long int number){

    long long int reversed =0, a, digits;

    if(number != 0){

        a = number %10;
        digits = numberOfDigits(number);
        return a* multiply(digits - 1) + reverseIntegerNumber(number /10);

    }
    
}

long long int numberOfDigits(long long int number){

    long long int digits;
    if(number != 0){
        digits =  1 + numberOfDigits(number /10);
        return digits;
    }
    return 0;
}

long long int multiply(long long int digits){
    
    if(digits == 0){
        return 1;
    }
    return 10 * multiply(digits-1);
}
