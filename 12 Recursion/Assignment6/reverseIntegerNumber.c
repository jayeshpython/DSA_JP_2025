
#include <stdio.h>

int reverseNumber(int, int);

int main(){

    int num, digit =0,a, power =1;
    printf("Enter number: ");
    scanf("%d", &num);

    a = num;
    while(a != 0){
        digit++;
        a = a/10;
    }

    for(int i = 1; i <digit; i++){
        power = power *10;
    }
    int reverse = reverseNumber(num, power);
    printf("\nReversed number: %d", reverse);

    return 0;
}

int reverseNumber(int num, int power){

    int result =0, a;
    if(num != 0){
        a = num %10;
        result = reverseNumber(num/10, power/10);
        result = a*power + result;
    }
    return result;
}