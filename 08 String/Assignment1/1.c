

#include <stdio.h>
#include <string.h>

void copyStringWithoutFunction(char a[], char b[]){

    int i;
    for(i = 0; a[i] != '\0'; i++){
        b[i] = a[i];
    }
    b[i] = '\0';
}

void copyStringwithFunction(char a[], char c[]){
    strcpy(c,a);
}

int main(){

    char a[20], b[20], c[20];

    printf("\n\tEnter string a: ");
    scanf("%[^\n]s", a);

    copyStringWithoutFunction(a,b);
    copyStringwithFunction(a,c);

    printf("\n\tString copied without using inbuilt function: %s", b);
    printf("\n\tString copied using inbuilt function: %s", c);
}
