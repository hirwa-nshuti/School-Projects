#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "seller.h"


int main()
{
    initialize_stock();
    available_items();
    add_items();
    display_stock();
    total_cost();
    return 0;
}