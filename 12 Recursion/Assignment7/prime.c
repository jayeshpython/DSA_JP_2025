
#include <stdio.h>

void primeNumber(long int, long int);

int main(){

    long int number;
    printf("Enter number: ");
    scanf("%ld", &number);

    primeNumber(number, 2);
    return 0;
}

void primeNumber(long int n, long int k){

    if(k < n){
        if(n % k == 0){
            printf("Not Prime number"); 
            return;
        }
        primeNumber(n, k+1);
    }
    else{
        printf("Prime Number");
        return;
    }
}