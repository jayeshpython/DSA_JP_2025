

#include <stdio.h>
#include <string.h>

void concatenateWithoutFunction(char a[], char b[], char result[]) {
    int i, j;
    for (i = 0; a[i] != '\0'; i++) {
        result[i] = a[i];
    }
    for (j = 0; b[j] != '\0'; j++, i++) {
        result[i] = b[j];
    }
    result[i] = '\0';
}

void concatenateWithFunction(char a[], char b[], char result[]) {
    strcpy(result, a);
    strcat(result, b);
}

int main() {
    char a[20];
    char b[20];
    char c[40];
    char d[40];

    printf("Enter string a: ");
    scanf(" %[^\n]", a);
    getchar();

    printf("Enter string b: ");
    scanf(" %[^\n]", b);

    concatenateWithoutFunction(a, b, c);
    printf("\nString after concatenation without using function: %s", c);

    concatenateWithFunction(a, b, d);
    printf("\nString after concatenation using function: %s\n", d);

    return 0;
}
