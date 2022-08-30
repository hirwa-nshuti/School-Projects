#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "seller.h"


int main()
{
    int n = 1;
    struct details *items = initialize_stock(n);
    display_stock(items, n);
    available_items(items, n);
    return 0;
}