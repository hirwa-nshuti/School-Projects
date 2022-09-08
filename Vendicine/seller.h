/*
The seller side library containing the functions that will allow the seller to access
all items in the stock, by adding and viewing available items in the stock.
*/
#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "client.h"

#ifndef Seller
#define Seller

// Showing the seller all available items in the stock.
void available_items()
{
    printf("\nYour current stock status is:\n\n");
    display_stock();
}

// Showing the recent purchase from the customers.
void recent_purchase()
{
    printf("\nThe customer named %s bought the following  %d %s items\n\n", customer_name, number, bought.name);
    fflush(stdout);
    available_items();
}

// Adding new items to the stock.
void add_items()
{
    int item_number;
    printf("\nHow many Items you want to add\n");
    scanf("%d", &item_number);
    int new_items = item_numbers + item_number;
    Det *new_list = (Det *)malloc(new_items * sizeof(Det)); // initializing a new array of needed size
    // copying item elements to new created array.
    for (int j = 0; j < item_numbers; j++)
    {
        new_list[j] = item[j];
    }
    free(item);
    item = new_list; // extending item to new created array.
    new_list = NULL;
    int i;
    // Adding items to the stock
    for (i = item_numbers; i < new_items; i++)
    {
        fflush(stdout);
        printf("Item name: \n");
        scanf("%s", item[i].name);
        fflush(stdout);
        printf("Item code: \n");
        scanf("%d", &item[i].code);
        fflush(stdout);
        printf("Quantity: \n");
        scanf("%d", &item[i].qty);
        fflush(stdout);
        printf("price: \n");
        scanf("%f", &item[i].price);
        fflush(stdout);
        printf("Manufacturing date(dd-mm-yyyy): \n");
        scanf("%d-%d-%d", &item[i].mfg.day,
              &item[i].mfg.month, &item[i].mfg.year);
    }
    item_numbers = new_items; // updating number of items in the stock.
}

// Calculating the total cost of all items in the stock.
void total_cost()
{
    double total_cost = 0;
    for (int i = 0; i < item_numbers; i++)
        total_cost += item[i].price * item[i].qty;
    printf("You have %d items which costs: %.3lf\n", item_numbers, total_cost);
}
#endif