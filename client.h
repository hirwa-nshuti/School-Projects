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
    for(int i = 0; i < item_numbers; i++)
    {
        if(item[i].code = item_code)
        {    
            out =  item[i];
            item_index = i;
        }
    }  
    return out;
}


void select_items()
{
    int selected_code=0;
    fflush(stdout);
    printf("Enter your name please: ");
    scanf("%s", customer_name);
    printf("\nSelect by entering the item code.\n");
    display_stock();
    fflush(stdout);
    printf("\nEnter the code: ");
    scanf("%d", &selected_code);
    bought = get_item(selected_code);
    printf("Enter how many %-15s items you want: ", bought.name);
    scanf("%d", &number);
    double total_cost = bought.price*number;
    printf("\nYou have successfully bought %d%-15s items for %.3lf amount\n", number, bought.name, total_cost);
}


#endif