#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct BST
{
    int price;
    char *name;
    struct BST *left;
    struct BST *right;
} node;

node *newNode(int price, char *name)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->price = price;
    temp->name = name;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("Price: %d, Item: %s\n", root->price, root->name);
        inorder(root->right);
    }
}

// A utility function to print preorder traversal of BST
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("Price: %d, Item name: %s\n", root->price, root->name);
    }
}

// A utility function to print preorder traversal of BST
void preorder(node *root)
{
    if (root != NULL)
    {
        preorder(root->right);
        preorder(root->left);
        printf("Price: %d, Item name: %s\n", root->price, root->name);
    }
}

// A utility function to find minimum value node in BST
node *minValueNode(node *to_search)
{
    node *current = to_search;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// A utility function to find maximum value node in BST
node *maxValueNode(node *to_search)
{
    node *current = to_search;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}
