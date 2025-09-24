
/*
Create a structure "Item" which includes below member variables:
   - itemName, quantity, price, amount.
   calculate the amount by accessing the member variable with the help of structure pointer.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
    char itemName[20];
    int quantity;
    int price;
    double amount;
}it;

void accept(it* ptr);
double calculateAmount(it* ptr);
void display(it* ptr);

int main(){
     it *ptr = (it*)malloc(sizeof(it));
    double Amount;

    accept(ptr);
    ptr->amount = calculateAmount(ptr);
    display(ptr);

    free(ptr);
    return 0;
}

void accept(it* ptr){
    printf("Enter item name: ");
    scanf("%s", ptr->itemName);

    printf("Enter quantity: ");
    scanf("%d", &ptr->quantity);

    printf("Enter price: ");
    scanf("%d", &ptr->price);
}

double calculateAmount(it* ptr){
    return ptr->quantity * ptr->price;
}

void display(it* ptr){
    printf("\nItem details");
    printf("\nItem name: %s", ptr->itemName);
    printf("\nQuantity: %d", ptr->quantity);
    printf("\nPrice: %d", ptr->price);
    printf("\nAmount: %lf", ptr->amount);
}



