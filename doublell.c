#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;

};
 struct node *head=NULL,*newnode,*tail,*current;
 int create()
 {
    int num;
    printf("\nEnter the number of elements in LL:");
    scanf("%d",&num);
    int i=0;
    while(i<num)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the  data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;

        if(head==NULL)
        {
            head=tail=newnode;
        }
        else
        {
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }
        i++;
    }
    return num;
 }
 void display()
 {
    current=head;
    while(current!=NULL)
    {
        printf("\t%d",current->data);
        current=current->next;
    }
    return;
 }
void insertBeg(int *num)
{
   
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        (*num)++;
        return;
}
void insertEnd(int *num)
{
  
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
        (*num)++;
        return;
}
void insertPos(int *num)
{     

      int pos;
        printf("\nEnter the pos to insert:");
        scanf("%d",&pos);
        if(pos<0 || pos>(*num)+1)
        {
        printf("Enter a valid position");
        return;
        }
        else if(pos==1)
        {
            insertBeg(num);
            return;
        }
        else if(pos==(*num)+1)
        {
            insertEnd(num);
            return;
        }
        else
        {
        current=head;
        for(int i=1;i<pos-1;i++)
        {
            current=current->next;
        }
        newnode->prev=current;
        newnode->next=current->next;
        current->next->prev=newnode;
        current->next=newnode;
        (*num)++;
        return;
        }
}
 void insert(int *num)
 {
        int inschoice=2;
    printf("\nWhere do want to insert 1.At Beginning 2.At End 3.At a position:\t");
    scanf("%d",&inschoice);
     newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the  data:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
    switch (inschoice)
    {
    case 1: insertBeg(num);
        break;
    case 2: insertEnd(num);
        break;
    case 3: insertPos(num);
    default:
    printf("Enter a correct choice");
        break;
    }
 }

void deleteBeg(int *num)
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        if(head->next==NULL)
        {
            free(head);
        }
        else
        {
            head=head->next;
            free(head->prev);
            head->prev=NULL;

        }
        (*num)--;
    }
    return;
}

void deleteEnd(int *num)
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        if(head->next==NULL)
        {
            free(head);
        }
        else
        {
            tail=tail->prev;
            free(tail->next);
            tail->next=NULL;
        }
        (*num)--;
    }
    return;
}

void delPos(int *num)
{
    int pos;
    printf("Enter position to delete: ");
    scanf("%d",&pos);
    if(pos<1)
    {
        printf("Invalid position");
    }
    else
    {
        if(pos==1)
        {
            deleteBeg(num);
            return;
        }
        else if(pos==*num)
        {
            deleteEnd(num);
        }
        else
        {   
            current=head;
            for(int i=1;i<pos;i++)
            {
                current=current->next;
            }
            current->prev->next=current->next;
            current->next->prev=current->prev;
            free(current);
            (*num)--;
        }
    }
}
void delete(int *num)
{
    int delchoice=2;
    printf("\nWhere do want to delete 1.At Beginning 2.At End 3.At a position 4. or a specific number:");
    scanf("%d",&delchoice);
    switch (delchoice)
    {
        case 1: deleteBeg(num);
        break;
        case 2: deleteEnd(num);
        break;
        case 3: delPos(num);
        break;
        // c
        default:printf("Enter a correct choice");
        break;
    }
    return;
}



 void main()
 {
    int num;
    num=create();
    display();
    insert(&num);
    while(1){
    delete(&num);
    display();}
 }
