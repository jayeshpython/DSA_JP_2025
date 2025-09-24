
/*
"In C, tell the user to set a password, then ask them to re-enter the password for confirmation. Take password input in a character array, 
compare the passwords and show a relevant message.
Sample 1: 
INPUT: 
Soham@5643
soham@5643
OUTPUT: Password didn’t match! Please try again
Sample 2: 
INPUT: 
        #include<CipherCoding>
        #include>CipherCoding>
OUTPUT: Password didn’t match! Please try again
Sample 3: 
INPUT: 
        eru42*sj#tdd$sfsea@uiji
        eru42*sj#tdd$sfsea@uiji
OUTPUT: Password matched!"
*/

#include<stdio.h>
#include<string.h>

void comparepassword(char *a,char *b){

	int i = 0, flag = 0;
	
	for(i = 0; a[i] !='\0' || b[i] !='\0'; i++){

		if(a[i] != b[i]){
			printf("\n\tInvalid password\n");
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		printf("\n\tPassword match\n");
	}
}

int main(){

	 char a[30], b[30];
        printf("\n\tEnter Password: ");
        fgets(a,sizeof(a),stdin);
		a[strcspn(a,"\n")]='\0';

        printf("\n\tRe-enter the Password for Confirmation: ");
        fgets(b,sizeof(b),stdin);
		b[strcspn(b,"\n")]='\0';

        comparepassword(a,b);
        return 0;
}