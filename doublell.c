#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL, *newnode, *current;
int size;
void create();
void insert();
void insertBeg();
void insertEnd();
void insertPos();
void display();
void delete();
void deleteBeg();
void deleteEnd();
void deletePos();

void create()
{
    int isize;
    size = 0;
    printf("\nEnter the intial number of elements: ");
    scanf("%d", &isize);
    for (int i = 0; i < isize; i++)
        insertEnd();
}

void insert()
{
    int op;
    printf("Enter a choice 1.Insert at Begin 2.Insert at end 3.Insert at a pos: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        insertBeg();
        break;
    case 2:
        insertEnd();
        break;
    case 3:
        insertPos();
        break;
    default:
        printf("\nEnter a valid operation!!!");
    }
}

void insertBeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d", &newnode->data);
    newnode->prev = newnode->next = NULL;
    if (head == NULL)
    {
        tail = head = newnode;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    size++;
}

void insertEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d", &newnode->data);
    newnode->prev = newnode->next = NULL;
    if (head == NULL)
    {
        tail = head = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    size++;
}
void insertPos()
{
    int pos;
    printf("\nEnter a position to insert[1-%d]: ", size + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > size + 1)
    {
        printf("\nInvalid position!!!");
        return;
    }
    else if (pos == 1)
    {
        insertBeg();
    }
    else if (pos == size + 1)
    {
        insertEnd();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data to insert: ");
        scanf("%d", &newnode->data);
        newnode->prev = newnode->next = NULL;
        current = head;
        for (int i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }
        newnode->next = current->next;
        current->next->prev = newnode;
        newnode->prev = current;
        current->next = newnode;
        size++;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nThe linked list is empty: ");
        return;
    }
    else
    {
        current=head;
        while (current!=NULL){
            printf("%d\t",current->data);
            current=current->next;
        }
    }
}

void delete()
{
    int op;
    if (head == NULL)
    {
        printf("\nThe linked list is empty: ");
        return;
    }
    printf("Enter a choice 1.Delete at Begin 2.Delete at end 3.Delete at a pos: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        deleteBeg();
        break;
    case 2:
         deleteEnd();
        break;
    case 3:
         deletePos();
        break;
    default:
        printf("\nEnter a vald operation!!!");
    }
}

void deleteBeg(){
    
    if(head==tail)
    {
        head=tail=NULL;
    }
    else{
        current=head;
        printf("%d deleted",current->data);
        head=head->next;
        free(current);
    }
    size--;
}
void deleteEnd(){
    if(head==tail)
    {
        head=tail=NULL;
    }
    else{
        current=tail;
        printf("%d deleted",current->data);
        tail=tail->prev;
        tail->next=NULL;
        free(current);
    }
    size--;
}

void deletePos()
{
    int pos;
    printf("\nEnter a position to delete[1-%d]: ", size );
    scanf("%d", &pos);
    if (pos < 1 || pos > size )
    {
        printf("\nInvalid position!!!");
        return;
    }
    else if (pos == 1)
    {
        deleteBeg();
    }
    else if (pos == size )
    {
        deleteEnd();
    }
    else
    {
        struct node * temp;
        current = head;
        for (int i = 1; i < pos - 1; i++)
        {
            current = current->next;
        }
        temp=current->next;
        current->next=temp->next;
        temp->next->prev=current;
        printf("%d deleted",temp->data);
        free(temp);
        size--;
    }
}
int main()
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
    return 0;
}
