

#include <stdio.h>
#include <stdlib.h>

void reverseString(char *str, int length);

int main() {
    char *str;
    int length = 0;

    str = (char*)malloc(100);
    if (str == NULL) return 1;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    while (str[length] != '\0') length++;

    reverseString(str, length);
    printf("Reversed string: %s\n", str);

    free(str);
    return 0;
}

void reverseString(char *str, int length) {
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
