
#include <stdio.h>

long long int numberOfDigit(long long int);

int main(){
    long long int n, result;
    printf("Enter number: ");
    scanf("%lld", &n);

    result = numberOfDigit(n);
    printf("Number of digits in number: %ld", result);
    return 0;
}

long long int numberOfDigit(long long int n){

    long long int cnt=0;

    if(n > 0){
        cnt = numberOfDigit(n/10);
        cnt++;
    }
    
    return cnt;
}