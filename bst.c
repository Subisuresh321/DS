#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL, *leaf, *newnode, *parent;

void insert()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    printf("\nEnter the data:");
    scanf("%d", &newnode->data);
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        leaf = root;
        parent = NULL;
        while (leaf != NULL)
        {
            parent = leaf;
            if (newnode->data < leaf->data)
                leaf = leaf->left;
            else
                leaf = leaf->right;
        }
        if (newnode->data < parent->data)
            parent->left = newnode;
        else
            parent->right = newnode;
    }
}


void create()
{
    int num;
    printf("\nEnter the initial numbers of nodes:");
    scanf("%d", &num);
    int i = 0;
    while (i < num)
    {
        insert();
        i++;
    }
}


void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void main()
{
    create();
    inorder(root);
}