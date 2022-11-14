#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

int main()
{
    node *root = NULL;
    printf("\nFirst\n");
    add_items(root, "nshs", 50);
    printf("\nshmd\n");
    add_items(root, "ks", 100);
    // printf("Hello");
    display_all_elemtents(root, 1);
    return 0;
}