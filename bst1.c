#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL, *parent = NULL,*succParent=NULL;
void create();
void insert();
struct node *insertEle(struct node *root, struct node *newnode);
void display(struct node *root);
void search();
struct node *searchEle(struct node *root, int ele);
void deleteEle(struct node *temp);
void delete();
struct node *findSucc(struct node *temp);

void main()
{
    create();
    display(root);
    search();
    delete ();
    delete ();
}

void create()
{
    int num;
    printf("Enter the initial number of nodes:\n");
    scanf("%d", &num);
    int i = 0;
    while (i < num)
    {
        insert();
        i++;
    }
}
void insert()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:\t\n");
    scanf("%d", &newnode->data);
    newnode->left = newnode->right = NULL;
    root = insertEle(root, newnode);
}

struct node *insertEle(struct node *root, struct node *newnode)
{
    if (root == NULL)
        root = newnode;
    else if (root->data > newnode->data)
        root->left = insertEle(root->left, newnode);
    else
        root->right = insertEle(root->right, newnode);
    return root;
}

void display(struct node *root)
{
    if (root == NULL)
        return;
    display(root->left);
    printf("%d\t\t", root->data);
    display(root->right);
}

void search()
{
    int ele;
    printf("\nEnter the element to search: \n");
    scanf("%d", &ele);
    if (searchEle(root, ele) != NULL)
    {
        printf("\nThe element %d found\n", ele);
    }
    else
    {
        printf("\nThe element %d not found\n", ele);
    }
}

struct node *searchEle(struct node *root, int ele)
{
    if (root == NULL || root->data == ele)
        return root;
    parent = root;
    if (root->data > ele)
        return searchEle(root->left, ele);
    else
        return searchEle(root->right, ele);
}

void delete()
{
    if (root == NULL)
    {
        printf("No element to delete\n");
        return;
    }
    else
    {
        struct node *temp;
        int ele;
        printf("Enter the element to delete: \n");
        scanf("%d", &ele);
        temp = searchEle(root, ele);
        if (temp == NULL)
        {
            printf("The element %d not found\n", ele);
        }
        else
        {
            deleteEle(temp);
            printf("The element %d Deleted\n", ele);
            display(root);
        }
    }
}

void deleteEle(struct node *temp)
{
    if (temp->left == NULL && temp->right == NULL)
    {
        if (temp == root)
        {
            root = NULL;
        }
        else if (parent->left == temp)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(temp);
    }
    else if (temp->left != NULL && temp->right != NULL)
    {   
        struct node *succ = findSucc(temp->right); 

        temp->data = succ->data;
        parent=succParent;
        deleteEle(succ);
    }
    else
    {
        struct node *child = temp->left != NULL ? temp->left : temp->right;
        temp->data = child->data;
        temp->left = child->left;
        temp->right = child->right;
        free(child);
    }
}

struct node *findSucc(struct node *temp)
{
    succParent=temp;
    while (temp->left != NULL)
    {
        succParent = temp;  
        temp = temp->left;
    }
    return temp;
}