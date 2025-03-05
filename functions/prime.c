
#include <stdio.h>
int main(){

    void prime(int *);
    int num;

    printf("Enter the number: ");
    scanf("%d", &num);
    
    prime(&num);
    return 0;
 }

 void prime(int *number){

    int flag=0, b=2;

    while(b < *number){

        if( *number % b == 0){
            flag =1;
            break;
        }
        b++;
    }
        if(flag == 1)
        printf("Not prime number");
        else 
        printf("Prime number");
 }