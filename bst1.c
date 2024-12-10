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
void indisplay(struct node *root);
void predisplay(struct node *root);
void postdisplay(struct node *root);
void search();
struct node *searchEle(struct node *root, int ele);
void deleteEle(struct node *temp);
void delete();
struct node *findSucc(struct node *temp);

void main()
{
     int op=0;
    while (op!=6)
    {
    printf("\nEnter any operation 1.Create 2.Display 3.Insert 4.Delete 5.Search 6.Exit \n");
    scanf("%d",&op);
        switch (op)
        {
        case 1:create();
            break;
        case 2:display(root);
            break;
        case 3:insert();
            break;
        case 4:delete();
            break;
        case 5:search();
            break;
        case 6: break;
        default: printf("Enter any valid operation!\n");
            break;
        }
    }
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
    printf("\nEnter the data:\t\n");
    scanf("%d", &newnode->data);
    newnode->left = newnode->right = NULL;
    root = insertEle(root, newnode);
    indisplay(root);
    printf("\n");
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
    int op=0;
    printf("\nEnter the type of display: 1.Inorder 2.Postorder 3.Preorder:\t\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:indisplay(root);
            break;
        case 2:postdisplay(root);
            break;
        case 3:predisplay(root);
            break;
        default:printf("Enter any valid operation!\n");
            break;
    }
}
void indisplay(struct node *root)
{
    if (root == NULL)
        return;
    indisplay(root->left);
    printf("%d\t\t", root->data);
    indisplay(root->right);
}

void postdisplay(struct node *root)
{
    if(root==NULL)
    return;
    postdisplay(root->left);
    postdisplay(root->right);
    printf("%d\t \t",root->data);
}

void predisplay(struct node *root)
{
    if(root==NULL)
    return;
    printf("%d\t \t",root->data);
    predisplay(root->left);
    predisplay(root->right);
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
        printf("\nEnter the element to delete: \n");
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
            indisplay(root);
            printf("\n");
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
        struct node *succ = findSucc(temp); 
        printf("\n%d is SUCC\n",succ->data);
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
    temp=temp->right;
    while (temp->left != NULL)
    {
        succParent = temp;  
        temp = temp->left;
    }
    return temp;
}