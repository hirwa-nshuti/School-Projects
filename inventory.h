#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

#ifndef Inventory
#define Inventory
struct date
{
    int day;
    int month;
    int year;
};
struct details
{
    char name[20];
    float price;
    int code;
    int qty;
    struct date mfg;
};

struct details *initialize_stock(int item_numbers)
{
    struct details *item = (struct details*)malloc(item_numbers * sizeof(struct details));
    int i;
    for(i = 0; i < item_numbers; i++)
    {
        fflush(stdin);
        printf("Item name: \n");
        scanf("%s", item[i].name);
        fflush(stdin);
        printf("Item code: \n");
        scanf("%d", &item[i].code);
        fflush(stdin);
        printf("Quantity: \n");
        scanf("%d", &item[i].qty);
        fflush(stdin);
        printf("price: \n");
        scanf("%f", &item[i].price);
        fflush(stdin);
        printf("Manufacturing date(dd-mm-yyyy): \n");
        scanf("%d-%d-%d", &item[i].mfg.day,
            &item[i].mfg.month, &item[i].mfg.year);  
    }

    return item;
}


void display_stock(struct details *item, int items_number)
{
    int i;
    printf("             *****  INVENTORY ***** \n");
    printf("------------------------------------------------------------------\n");
    printf(" S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE MFG.DATE \n");
    printf("------------------------------------------------------------------\n");
    for (i = 0; i < items_number; i++)
        printf("%d     %-15s        %-d          %-5d     %-3f %d/%d/%d \n", i + 1, item[i].name, item[i].code, item[i].qty,
            item[i].price, item[i].mfg.day, item[i].mfg.month,
            item[i].mfg.year);
    printf("-----------------------------------------------------------------\n");
}

#endif