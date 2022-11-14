`#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "items.h"
#include "database.h"

/*Predefined functions*/
char *file = "file.txt";
void update_database(node *curr);
void display_all_elemtents(node *root, int disp_mode);

// A utility function to determine whether a node is present in BST
int search(node *root, int search_price)
{
    if (root == NULL)
        return 0;
    if (root->price == search_price)
        return 1;
    if (root->price > search_price)
        return search(root->left, search_price);
    return search(root->right, search_price);
}

// A utility function to insert a new node with given price in BST
void insert_node_to_tree(node *root, int to_ins_price, char *ins_name)

{
    node *to_insert = newNode(to_ins_price, ins_name);
    if (to_insert->price < root->price)
    {
        if (root->left != NULL)
            insert_node_to_tree(root->left, to_insert->price, to_insert->name);
        else
            root->left = to_insert;
    }
    if (to_insert->price > root->price)
    {
        if (root->right != NULL)
            insert_node_to_tree(root->right, to_insert->price, to_insert->name);
        else
            root->right = to_insert;
    }
    delete_file_content(file);
    update_database(root);
    // return root;
}

// A utility function to add items to the database
node *add_items(node *root, char *name, int price)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->name = name;
    new_node->price = price;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        node *current_node = root;
        while (current_node != NULL)
        {
            if (price < current_node->price)
            {
                if (current_node->left != NULL)
                {
                    current_node = current_node->left;
                }
                else
                {
                    current_node->left = new_node;
                    break;
                }
            }
            else if (price > current_node->price)
            {
                if (current_node->right != NULL)
                {
                    current_node = current_node->right;
                }
                else
                {
                    current_node->right = new_node;
                    break;
                }
            }
        }
    }

    delete_file_content(file);
    update_database(root);
    return root;
}
// A utility function to delete from a BST
node *delete_node_from_tree(node *root, int del_price)
{

    if (search(root, del_price) == 0)
    {
        printf("\nItem not found in the tree\n");
        return root;
    }
    if (root == NULL)
        return root;
    if (del_price < root->price)
        root->left = delete_node_from_tree(root->left, del_price);
    else if (del_price > root->price)
        root->right = delete_node_from_tree(root->right, del_price);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = minValueNode(root->right);
        root->price = temp->price;
        root->right = delete_node_from_tree(root->right, temp->price);
    }
    delete_file_content(file);
    update_database(root);
    return root;
}

void display_all_elemtents(node *root, int disp_mode)
{
    if (disp_mode == 1)
        inorder(root);
    else if (disp_mode == 2)
        preorder(root);
    else if (disp_mode == 3)
        postorder(root);
    else
        printf("Invalid display mode");
}

// A utility function to find sum of all elements in BST
int sum_of_all_elements(node *root)
{
    if (root == NULL)
        return 0;
    return (root->price + sum_of_all_elements(root->left) + sum_of_all_elements(root->right));
}

char *get_item_name(node *root, int search_price)
{
    if (root == NULL)
        return NULL;
    if (root->price == search_price)
        return root->name;
    if (root->price > search_price)
        return get_item_name(root->left, search_price);
    return get_item_name(root->right, search_price);
}

// Update database function
void update_database(node *curr)
{
    if (curr != NULL)
    {
        update_database(curr->left);
        char *price_conv = convert_int_to_string(curr->price);
        char *nam = get_item_name(curr, curr->price);
        char *to_write = concatenate_strings(price_conv, nam);
        write_single_line(file, to_write);
        update_database(curr->right);
    }
}
