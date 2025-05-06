#include <stdio.h>

int main() {
    char str[20];
    char *ptr;

    printf("Enter string: ");
    scanf("%[^\n]s", str);

    ptr = str;

    printf("You entered string: ");
    while (*ptr != '\0') {
        printf("%c", *ptr);  
        ptr++;              
    }
    printf("\n");

    return 0;
}
