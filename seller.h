#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "client.h"

#ifndef Seller
#define Seller

void available_items(struct details *items, int item_number)
{
    printf("\nYour current stock status is:\n");
    display_stock(items, item_number);
}

void current_purchases(struct details *purchase, int item_number, char customer[20])
{
    printf("\nThe %s customer bought the following items:\n", customer);
    display_stock(purchase, item_number);
}
#endif