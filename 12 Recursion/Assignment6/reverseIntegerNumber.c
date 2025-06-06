
#include <stdio.h>

long long int reverseIntegerNumber(long long int);

int main(){

    long long int number, result;
    printf("Enter number: ");
    scanf("%lld", &number);

    result = reverseIntegerNumber(number);
    printf("Reversed number: %lld", result);

    return 0;
}

long long int reverseIntegerNumber(long long int number){

    long long int reversed =0, a;


    if(number >0){
        a = number % 10;
        reversed = reversed*10 + a;
        reversed = reverseIntegerNumber(number / 10, reversed*10 +a);
    }
    return reversed;
}

