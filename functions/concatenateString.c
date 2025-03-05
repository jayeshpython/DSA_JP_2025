

#include <stdio.h>
#include <stdlib.h>

void concatenateStrings(char *str1, char *str2, char *result);

int main() {
    char *str1, *str2, *result;
    int size1, size2;

    printf("Enter the size of the first string: ");
    scanf("%d", &size1);
    printf("Enter the size of the second string: ");
    scanf("%d", &size2);

    str1 = (char*)malloc(sizeof(char) * (size1 + 1));
    str2 = (char*)malloc(sizeof(char) * (size2 + 1));
    result = (char*)malloc(sizeof(char) * (size1 + size2 + 1));

    printf("Enter the first string: ");
    scanf(" ");
    scanf("%[^\n]", str1);

    printf("Enter the second string: ");
    scanf(" "); 
    scanf("%[^\n]", str2);

    concatenateStrings(str1, str2, result);
    printf("Concatenated string: %s\n", result);

    free(str1);
    free(str2);
    free(result);

    return 0;
}

void concatenateStrings(char *str1, char *str2, char *result) {
    int i, j;

    for (i = 0; str1[i] != '\0'; i++) {
        result[i] = str1[i];
    }
    for (j = 0; str2[j] != '\0'; j++) {
        result[i + j] = str2[j];
    }
    result[i + j] = '\0'; 
}
