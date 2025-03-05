
#include <stdio.h>
int main(){

    void amstrong(int**);

    int num=3;
    int *p1 = &num;
    int **p2 = &p1;

    printf("Enter the number: ");
    scanf("%d", &num);

    amstrong(p2);
    return 0;
}

void amstrong(int **num){

    int amt, oriNum = **num, n = **num;

    while(n >0){
        int a = n%10;
        amt = amt + (a*a*a);
        n = n/10;
    }
    if(amt == oriNum)
    printf("The number is amstrong");
    else
    printf("Not amstron");
    }   

