#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int num;
struct node *newnode, *head = NULL, *current;
void insEnd();
void create()
{
    printf("\nEnter the number of elements:");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
        insEnd(0);
    return;
}

void display()
{

    if (head == NULL)
    {
        printf("\nLinked list is empty");
    }
    else
    {
        current = head;
        do
        {
            printf("%d\t", current->data);
            current = current->next;
        } while (current != head);
    }
    return;
}
void insBeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {

        head = newnode;
        newnode->next = head;
    }
    else
    {
        current=head;
        while (current->next!=head)
        {
            current=current->next;
        }
        newnode->next=head;
        current->next=newnode;
        head=newnode;
    }
    num++;
    return;
}
void insEnd(int flag)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    printf("\nEnter the data: ");
    scanf("%d", &newnode->data);
    if (head == NULL)
    {

        head = newnode;
        newnode->next = head;
    }
    else
    {
        current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = head;
    }
    if(flag)
    num++;
    return;
}

void insPos()
{
    int pos;
    printf("Enter a Postion <= %d :",num);
    scanf("%d",&pos);
    if(pos>num || pos<1)
    {
        printf("Enter a valid position");
        insPos();
    }
    else if(pos==1)
    insBeg();
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        current=head;
        for(int i=1;i<pos-1;i++)
        {
            current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;
    }
    num++;
    return;
}
void insert()
{
    int insop=1;
    printf("\nInsert at 1.At beginning 2.At end 3.At a position:\t");
    scanf("%d",&insop);
    switch (insop)
    {
    case 1:insBeg();
        break;
    case 2:insEnd(1);
        break;
    case 3: insPos();
        break;
    default: printf("Enter the valid opertion");
            insert();
        break;
    }
    return;
}
void main()
{
    create();
    while(1)
    {
    display();
    insert();
    }
}