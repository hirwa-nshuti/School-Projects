#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manager.h"

int main()
{
    printf("\nWelcome to the Store Management App!!!\n");
    int select;
selection:
    printf("\n\n--------MENU--------\n");
    printf("\n1. Add Items\n");
    printf("\n2. Display All Items\n");
    printf("\n3. Expensive Or Cheap Item\n");
    printf("\n4. Delete Item\n");
    printf("\n5. Calculate Total Cost of Store\n");
    printf("\n6. Exit\n");
    printf("---------\n");
    printf("Enter your choice: ");
    scanf("%d", &select);
    node *root;
    if (select == 1)
    {
        printf("\nWhat is the name of your Item to add?: ");
        char name[MAX];
        scanf("%s", name);
        printf("\nHow Much is your Item to add?: ");
        int price;
        scanf("%d", &price);
        node *new = add_items(root, name, price);
        root = new;
        display_all_elemtents(new, 1);
    }

    else if (select == 2)
    {
        printf("\nSelect\n%d to display inorder,\n%d to display preorder,\n%d to display postorder\n: ", 1, 2, 3);
        int choice;
        scanf("%d", &choice);
        display_all_elemtents(root, choice);
    }
    else if (select == 3)
    {
        printf("\nselect %d to display expensive item,\n%d to display q cheap item: ", 1, 2);
        int choice;
        scanf("%d", &choice);
        node *item;
        if (choice == 1)
        {
            item = maxValueNode(root);
            printf("\nexpensive item is %s with price %d\n", item->name, item->price);
        }
        else if (choice == 2)
        {
            item = minValueNode(root);
            printf("\ncheap item is %s with price %d\n", item->name, item->price);
        }
    }
    else if (select == 4)
    {
        printf("\nHow Much is your Item to delete?: ");
        int price;
        scanf("%d", &price);
        node *temp = delete_node_from_tree(root, price);
        printf("\nItem deleted successfully!!!\n");
        root = temp;
    }
    else if (select == 5)
    {
        int total = sum_of_all_elements(root);
        printf("\nThe total cost of your store is: %d\n", total);
    }
    else
        goto thankyou;
    goto selection;
thankyou:
    printf("\nThank you for using our application");
    printf("\u263A\n");
    exit(0);
}