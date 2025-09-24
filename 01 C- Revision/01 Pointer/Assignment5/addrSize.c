
// write Program to print addresses and size of all types of pointer variables.
 
#include <stdio.h>

int main() {
    int a = 10;
    float b = 20.5;
    char c = 'X';

    int *p1 = &a;
    float *p2 = &b;
    char *p3 = &c;

    printf("Address of a: %p, Size of int pointer: %zu bytes\n", p1, sizeof(p1));
    printf("Address of b: %p, Size of float pointer: %zu bytes\n", p2, sizeof(p2));
    printf("Address of c: %p, Size of char pointer: %zu bytes\n", p3, sizeof(p3));

    return 0;
}
