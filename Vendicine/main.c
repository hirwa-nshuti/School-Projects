/*
The main program of our application
-----------------------------------
Including all the three header files,
and invoke the functions from header files according to the user choice.

We have two options to login as the client or seller.
But to get the better exerience it is mandatory for the seller to login first and initialize stock.
before performing any other operation and do other operatations accordingly without quiting.

*/
#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "seller.h"
#include "client.h"

int main()
{
    printf("\nWelcome to the Vendicine\n");
    int main_choice;
    do
    {

        printf("\nMenu:\n\n");
        printf("     1. Client     \n");
        printf("     2. Seller     \n");
        printf("     0. Quit     \n");
        printf("--------------------\n");
        scanf("%d", &main_choice);
        switch (main_choice)
        {
        case 1:
            printf("\nSuccessfully logged in as the Client.\n");
            select_items();
            break;
        case 2:
            printf("\nSuccessfully logged in as the Seller.\n");
            int seller_choice;
            do
            {
                printf("\nSeller's Menu:\n\n");
                printf("     1. Initialize Stock    \n");
                printf("     2. Add items     \n");
                printf("     3. View total cost     \n");
                printf("     4. View available items     \n");
                printf("     5. To view recent purchase     \n");
                printf("-------------------------------------\n");
                scanf("%d", &seller_choice);
                switch (seller_choice)
                {
                case 1:
                    initialize_stock();
                    break;
                case 2:
                    add_items();
                    break;
                case 3:
                    total_cost();
                    break;
                case 4:
                    available_items();
                    break;
                case 5:
                    recent_purchase();
                    break;
                case 0:
                    printf("\nLogging out\n");
                    break;
                default:
                    break;
                }
            } while (seller_choice <= 5 && seller_choice > 0);

            break;
        case 0:
            printf("\nThank you for using VENDICINE.\n");
            break;
        default:
            break;
        }
    } while (main_choice > 0 && main_choice < 3);

    return 0;
}