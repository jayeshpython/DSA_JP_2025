
// write a  Program to count vowels and consonants in a string using pointer.

#include <stdio.h>

int main(){
	
	char ch[20];
	char *ptr;
	int vowels = 0, consonents = 0;
	
	printf("Enter string: ");
	scanf("%[^\n]s", ch);
	
	ptr = ch;
	
	for(int i = 0; ptr[i] != '\0'; i++) {
		if(ptr[i] == 65 || ptr[i] == 69 || ptr[i] == 73 || ptr[i] == 79 || ptr[i] == 85 || 
		   ptr[i] == 97 || ptr[i] == 101 || ptr[i] == 105 || ptr[i] == 111 || ptr[i] == 117) {
			vowels++;
		} else if((ptr[i] >= 65 && ptr[i] <= 90) || (ptr[i] >= 97 && ptr[i] <= 122)) {
			consonents++;
		}
	}
	
	printf("Number of vowels: %d\n", vowels);
	printf("Number of consonents: %d\n", consonents);
	
	return 0;
}
