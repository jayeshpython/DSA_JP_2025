
#include <stdio.h>
int main(){

    int m1,m2, m3, avg;

    void accept(int* ,int*, int*);
    int calculate(int , int ,int);
    void display(int);

    accept(&m1, &m2, &m3);
    avg = calculate(m1, m2, m3);
    display(avg);
    return 0;
}

void accept(int* a, int* b, int* c){
    printf("Enter the marks: ");
    scanf("%d, %d, %d", a,b,c);
}

int calculate(int x, int y, int z){
    int avg;
    avg = (x+y+z)/3;
    return avg;
}

void display(int average){
    printf("The average marks are: %d\n", average);
}