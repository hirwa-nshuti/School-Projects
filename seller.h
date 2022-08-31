#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "client.h"

#ifndef Seller
#define Seller

void available_items()
{
    printf("\nYour current stock status is:\n\n");
    display_stock();
}

void current_purchases()
{
    printf("\nThe customer named %s bought the following items %d %s:\n\n", customer_name, number, bought.name);
    item[item_index].qty -= number;
    fflush(stdout);
    available_items();
}

void add_items()
{
    int item_number;
    printf("\nHow many Items you want to add\n");
    scanf("%d", &item_number);
    int new_items = item_numbers + item_number;
    Det *new_list = (Det *)malloc(new_items * sizeof(Det));
    for (int j = 0; j < item_numbers; j++)
    {
        new_list[j] = item[j];
    }
    free(item);
    item = new_list;
    new_list = NULL;
    int i;
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
    item_numbers = new_items;
}

void total_cost()
{
    double total_cost = 0;
    for (int i = 0; i < item_numbers; i++)
        total_cost += item[i].price * item[i].qty;
    printf("You have %d items which costs: %.3lf\n", item_numbers, total_cost);
}
#endif