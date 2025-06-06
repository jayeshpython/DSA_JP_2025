
#include <stdio.h>

long long int pallindrome(long long int);

int main(){

    long long int number, result;
    printf("Enter number: ");
    scanf("%lldd", &number);

    result = pallindrome(number);
    if(result == number){
        printf("Number is pallindrome");
    }
    else
    printf("Number is not pallindrome");

    return 0;
}

long long int pallindrome(long long int number){

    long long int multiply =1, n = number, reversed =0, cnt =0, a;

    if(number != 0){

        while(n != 0){
            cnt++;
            n = n/10;
        }

        for(int i =1; i<cnt; i++){
            multiply = multiply *10;
        }

        a = number %10;

        reversed = pallindrome(number /10);
        return (reversed + multiply *a);
    }
}