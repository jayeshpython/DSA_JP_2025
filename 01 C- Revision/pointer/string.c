

#include <stdio.h>
int main(){
	
	char str[20];
	char *ptr;
	
	printf("Enter string: ");
	scanf("%[^\n]s", str);

	ptr = str;
	
	printf("You entered string: ");
	for(int i=0; ptr[i] != '\0'; i++)
	{
		printf("%c", ptr[i]);
	}
	printf("\n");
	
	return 0;
}