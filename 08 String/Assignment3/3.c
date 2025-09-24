
//Accept a string and reverse the content of string 

#include<stdio.h>
#include<string.h>

int main()
{
	char ch[20];
	int count = 0;

	printf("Enter the string: ");
    scanf("%[^\n]s",ch);

	for(int i = 0; ch[i] !='\0'; i++){
		count++;
	}
	for(int i = 0, j = count-1; i < j; i++,j--)
	{
		char temp = ch[i];
		ch[i] = ch[j];
		ch[j] = temp;
	}
	printf("\nReverse content is: %s", ch);
	return 0;
}