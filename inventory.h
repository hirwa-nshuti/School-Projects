/*
The inventory library to keep track of our stock by initializing and adding items to the stock.
Two main functions here:
-----------------------
initialize_stock(), The seller has to first initialize items in the stock for them to be available for clients.
display_stock(), It helps both client and seller to know current items in the stock.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

#ifndef Inventory
#define Inventory

// Storing the date information in a structure
struct date
{
    int day;
    int month;
    int year;
};

// Initializing a structure of item details and type defining it to Det.
typedef struct details
{
    char name[MAX_SIZE];
    float price;
    int code;
    int qty;
    struct date mfg;
} Det;

Det *item;        // Declaring a pointer that stores array of items.
int item_numbers; // global value to keep track of items we have in the array.
void initialize_stock()
{
    printf("\nEnter the number of items to initialize\n");
    scanf("%d", &item_numbers);
    item = (Det *)malloc(item_numbers * sizeof(Det)); // Initializing the size of array of items
    int i;
    // Getting items to register in the stock.
    for (i = 0; i < item_numbers; i++)
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
}

// Displaying the stock contents a table showing items in the stock with full details.
void display_stock()
{
    int i;
    printf("                      *****  INVENTORY ***** \n");
    printf("------------------------------------------------------------------\n");
    printf(" S.N.|      NAME           |    CODE   |  QUANTITY |  PRICE    |     MFG.DATE \n");
    printf("---------------------------------------------------------------------------\n");
    for (i = 0; i < item_numbers; i++)
        printf("%d.     %-15s         %-d        %-5d      %.3f         %d/%d/%d \n", i + 1, item[i].name, item[i].code, item[i].qty,
               item[i].price, item[i].mfg.day, item[i].mfg.month,
               item[i].mfg.year);
    printf("----------------------------------------------------------------------------\n");
}

#endif