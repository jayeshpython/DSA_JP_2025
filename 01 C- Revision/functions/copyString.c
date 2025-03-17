

#include <stdio.h>
#include <stdlib.h>

void copyString(char *ch, char *str);

int main() {
    char *ch, *str;
    int size;

    printf("Enter the size: ");
    scanf("%d", &size);

 
    ch = (char*)malloc(sizeof(char) * (size + 1));
    str = (char*)malloc(sizeof(char) * (size + 1));

    printf("Enter the string: ");
    scanf(" ");
    scanf("%[^\n]", ch); 

    copyString(ch, str);

    printf("Copied string: %s\n", str);
    free(ch);
    free(str);

    return 0;
}

void copyString(char *ch, char *str) {
    int i = 0;
    while (ch[i] != '\0') {
        str[i] = ch[i];
        i++;
    }
    str[i] = '\0'; 
}

for(int i=0; a[i] != '\0'; i++){
	a[i] = ch[i];
	
