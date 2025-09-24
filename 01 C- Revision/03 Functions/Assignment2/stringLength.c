
//write a function to find the length of a string.

#include <stdio.h>
#include <stdlib.h>
int main(){
	
	char* ch;
	int size, length=0;
	
	int lengthOfString(char*, int);
	
	printf("Enter the size: \n");
	scanf("%d", &size);
	
	ch = (char*)malloc(sizeof(char)*(size+1));
	
	printf("Enter string: ");
	 scanf(" "); 
    scanf("%[^\n]", ch);
	
	length = lengthOfString(ch, size);
	printf("The length of the string: %d", length);
	free(ch);
	return 0;
}

int lengthOfString(char* ch, int size){
	int length=0;
	
	for(int i=0; ch[i] != '\0'; i++){
		length++;
	}
	return length;
}