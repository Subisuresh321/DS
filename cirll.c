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
        current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        newnode->next = head;
        current->next = newnode;
        head = newnode;
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
    if (flag)
        num++;
    return;
}

void insPos()
{
    int pos;
    printf("Enter a Postion <= %d :", num);
    scanf("%d", &pos);
    if (pos > num || pos < 1)
    {
        printf("Enter a valid position");
        insPos();
    }
    else if (pos == 1)
        insBeg();
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        printf("\nEnter the data: ");
        scanf("%d", &newnode->data);
        current = head;
        for (int i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
    num++;
    return;
}
void insert()
{
    int insop = 1;
    printf("\nInsert at 1.At beginning 2.At end 3.At a position:\t");
    scanf("%d", &insop);
    switch (insop)
    {
    case 1:
        insBeg();
        break;
    case 2:
        insEnd(1);
        break;
    case 3:
        insPos();
        break;
    default:
        printf("\nEnter the valid opertion");
        insert();
        break;
    }
    return;
}

void delBeg()
{
    if (head == NULL)
        printf("\nLinked list is empty");
    else
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct node *temp;
            temp = current = head;
            while (current->next != head)
            {
                current = current->next;
            }
            head = head->next;
            current->next = head;
            free(temp);
        }
        num--;
    }
}

void delEnd()
{
    if (head == NULL)
        printf("\nLinked list is empty");
    else
    {
        if (head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            struct node *temp;
            current = head;
            while (current->next->next != head)
            {
                current = current->next;
            }
            temp = current->next;
            current->next = head;
            free(temp);
        }
        num--;
    }
}

void delPos()
{
    int pos;
    printf("Enter a Postion <= %d :", num);
    scanf("%d", &pos);
    if (pos > num || pos < 1)
    {
        printf("Enter a valid position");
        delPos();
    }
    else if (pos == 1)
        delBeg();
    else
    {
        struct node *temp;
        current = head;
        for (int i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }
        temp = current->next;
        current->next = current->next->next;
        free(temp);
        num--;
    }
    return;
}
void delete()
{
    int delop;
    printf("\nWhere do you want to delete 1. At Beginning 2. At End 3. At a position: ");
    scanf("%d", &delop);
    switch (delop)
    {
    case 1:
        delBeg();
        break;
    case 2:
        delEnd();
        break;
    case 3:
        delPos();
        break;
    default:
        printf("Enter a correct choice\n");
        delete ();
        break;
    }
}
void main()
{

    int op = 0;
    while (op != 5)
    {
        printf("\nEnter an option:\t1.Create\t2.Display\t3.Insert\t4.Delete\t5.Exit\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            break;
        default:
            printf("Enter a valid option\n");
            break;
        }
    }
}