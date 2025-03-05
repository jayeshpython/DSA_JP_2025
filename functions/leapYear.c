
#include <stdio.h>
int main(){

    void leap(int*);
    int year;
     
    printf("Enter the year: ");
    scanf("%d", &year);

    leap(&year);
    return 0;
}

void leap(int * leapYear){
    if((*leapYear % 4==0) || (*leapYear %400 ==0) && (*leapYear %100 !=0))
    printf("leap year");
    else
    printf("not leap year");
}