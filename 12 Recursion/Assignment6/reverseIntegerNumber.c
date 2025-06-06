
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

    long long int reversed =0, cnt =0, n = number, multiply = 1, a;

    if(number != 0){

        while(n != 0){
            cnt++;
            n = n/10;
        }
  
        for(int i =1; i<cnt; i++){
            multiply = multiply * 10;
        }

        a = number %10;
        reversed = reverseIntegerNumber(number /10);
        return (reversed + multiply *a);
    }
    
}

