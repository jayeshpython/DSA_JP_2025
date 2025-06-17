

#include <stdio.h>

int lcmOfTwoNumbers(int , int);
int origNum(int, int, int, int);

int main(){

    int a,b, lcm;
    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    lcm = lcmOfTwoNumbers(a,b);
    printf("\nThe LCM of two numbers is: %d", lcm);

    return 0;
}

int lcmOfTwoNumbers(int a, int b){

    return origNum(a, b, a, b);
}

int origNum(int a, int b, int a1, int b1){

    if(a == b)
    return a;

    if(a < b)
    return origNum(a+a1, b, a1, b1);

    else
    return origNum(a, b+b1, a1, b1);
}