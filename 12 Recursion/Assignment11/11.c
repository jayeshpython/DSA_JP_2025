
//accept a string and calculate the length of string  using recursion

#include <stdio.h>

int stringLength(char[]);

int main(){

    char ch[30];
    printf("Enter string: ");
    scanf("%[^\n]s", ch);

    int length;
    length = stringLength(ch);
    printf("\nLength of string: %d", length);

    return 0;
}

int stringLength(char ch[]){

    static int cnt = 0;
    if(ch[0] !=  '\0'){
        cnt++;
        stringLength(ch +1);
    }
    return cnt;
}