
#include <stdio.h>

double calculatePower(double, double);

int main(){
    double base, exponent, result;
    printf("Enter base: ");
    scanf("%lf", &base);

    printf("Enter exponent: ");
    scanf("%lf", &exponent);

    result = calculatePower(base, exponent);
    printf("The power of number n is: %lf", result);
    return 0;
}

double calculatePower(double base, double exponent){

    double power = 1;
    if(exponent > 1){
        power = calculatePower(base, exponent -1);
    }

    return (power * base);
}
