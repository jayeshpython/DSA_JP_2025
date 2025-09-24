
//Write the code to covert the below expression from Infix to Prefix : F*(A+B)/E-D*(G+H/K)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 50

char* postfix(char*);
char* prefix(char*);
int isAlpha(char);
int prior(char);
void evaluate(char*);
int push(char operand[][MAX], int top, char ch);
void reverse(char*);

int main() {
    int ch;
    char str[MAX], *pre = NULL;

    while (1) {
        printf("\n\t********* Postfix Conversion *********");
        printf("\n\t1. Enter Infix Expression");
        printf("\n\t2. Convert to Prefix");
        printf("\n\t3. Evaluate Prefix");
        printf("\n\t4. Exit");

        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);
        getchar();

        switch (ch) {
            case 1:
                printf("\n\tEnter infix expression: ");
                scanf("%s", str);
                break;

            case 2:
                pre = prefix(str);
                if (pre != NULL)
                    printf("\n\tPrefix = %s", pre);
                break;

            case 3:
                if (pre != NULL)
                    evaluate(pre);
                else
                    printf("\n\tPlease convert to prefix first");
                break;

            case 4:
                exit(0);

            default:
                printf("\n\tInvalid choice");
        }
    }

    return 0;
}

int isAlpha(char ch) {
    return isalnum(ch);
}

int prior(char ch) {
    switch (ch) {
        case '^': return 4;
        case '*':
        case '/':
        case '%': return 3;
        case '+':
        case '-': return 2;
        case '(': return 1;
        default: return 0;
    }
}

int push(char operand[][MAX], int top, char op) {

    char temp[MAX];
    temp[0] = op;
    temp[1] = '\0';

    if (top > 0) {
        strcat(operand[top - 1], operand[top]);
        strcat(operand[top - 1], temp);
        top--;
    } 
    else {
        printf("\n\tInvalid expression!");
        exit(1);
    }
    return top;
}

char* postfix(char* str) {

    static char result[MAX];
    char operand[MAX][MAX], op[MAX];
    int top = -1, top1 = -1, i;

    for (i = 0; str[i] != '\0'; i++) {

        if (isAlpha(str[i])) {
            top++;
            operand[top][0] = str[i];
            operand[top][1] = '\0';
        } 
        else if (str[i] == '(') {
            op[++top1] = str[i];
        } 
        else if (str[i] == ')') {
            while (top1 >= 0 && op[top1] != '(') {
                top = push(operand, top, op[top1--]);
            }
            if (top1 < 0) {
                printf("\n\tInvalid expression!");
                return NULL;
            }
            top1--; // pop '('
        } 
        else {
            while (top1 >= 0 && prior(str[i]) <= prior(op[top1]) && op[top1] != '(') {
                top = push(operand, top, op[top1--]);
            }
            op[++top1] = str[i];
        }
    }

    while (top1 >= 0) {

        if (op[top1] == '(') {
            printf("\n\tInvalid expression!");
            return NULL;
        }
        top = push(operand, top, op[top1--]);
    }

    strcpy(result, operand[top]);
    return result;
}

void evaluate(char* str) {

    int stack[MAX], top = -1, i;

    for (i = 0; str[i] != '\0'; i++) {

        if (isdigit(str[i])) {
            stack[++top] = str[i] - '0';
        } 
        else if (isalpha(str[i])) {
            int val;
            printf("\n\tEnter value for %c: ", str[i]);
            scanf("%d", &val);
            stack[++top] = val;
        } 
        else {
            int b = stack[top--];
            int a = stack[top--];
            switch (str[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
                case '%': stack[++top] = a % b; break;
                case '^': stack[++top] = pow(a, b); break;
                default: printf("\n\tInvalid operator"); exit(1);
            }
        }
    }

    printf("\n\tResult = %d", stack[top]);
}

char* prefix(char* infix){

    static char rev[MAX], temp[MAX], *post;
    strcpy(temp, infix);

    reverse(temp);

    for(int i = 0; temp[i] != '\0'; i++){

        if(temp[i] == '(')
        temp[i] = ')';
        else if(temp[i] == ')')
        temp[i] = '(';
    }

    post = postfix(temp);
    if (post == NULL)
        return NULL;

    strcpy(rev, post);
    reverse(rev);

    return rev;
}

void reverse(char* str) {

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}
