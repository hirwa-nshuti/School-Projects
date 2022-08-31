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
typedef struct details
{
    char name[MAX_SIZE];
    float price;
    int code;
    int qty;
    struct date mfg;
} Det;

Det *item;
int item_numbers;
void initialize_stock()
{
    printf("\nEnter the number of items to initialize\n");
    scanf("%d", &item_numbers);
    item = (Det *)malloc(item_numbers * sizeof(Det));
    int i;
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