/*
The Client side of the application it is holding two main functions
The get_item() function which will help to get item from our inventory based on input item code.
The select_item() function for helping the client to select item to buy from the stock.
*/
#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"

#ifndef Client
#define Client

Det bought;
int number, item_index;
char customer_name[MAX_SIZE];

Det get_item(int item_code)
{
    Det out;
    // Iterating through item list to get the item with given item code
    for (int i = 0; i < item_numbers; i++)
    {
        if (item[i].code = item_code)
        {
            out = item[i];
            item_index = i;
        }
    }
    return out;
}

void select_items()
{
    int selected_code = 0;
    fflush(stdout);
    printf("Enter your name please: ");
    scanf("%s", customer_name);
    printf("\nSelect by entering the item code.\n");
    display_stock();
    fflush(stdout);
    printf("\nEnter the code: ");
    scanf("%d", &selected_code);
    bought = get_item(selected_code); // Getting the selected item.
    printf("Enter how many %-15s items you want: ", bought.name);
    scanf("%d", &number);                      // getting the how many items to buy.
    double total_cost = bought.price * number; // computing the total price of the bought items.
    printf("\nYou have successfully bought %d %s items for %.3lf amount\n", number, bought.name, total_cost);
    item[item_index].qty -= number; // reducing the bough number of items from the stock.
}

#endif