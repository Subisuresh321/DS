#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *head,*newnode,*current;
void create()
{
int num;
head=NULL;
printf("Enter the number of elements:\t");
scanf("%d", &num);
for(int i=0;i<num;i++){
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data");
scanf("%d",&newnode->data);
if(head==NULL)
{
head=newnode;
current=newnode;
}
else
{
current->next=newnode;
current=newnode;
}
}
current->next=NULL;
return;
}

void display()
{
current=head;
while(current!=NULL)
{
printf("%d\t", current->data);
current=current->next;

}
return;
}

void insert()
{
int pos;
printf("\nEnter the pos to insert");
scanf("%d", &pos);
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data");
scanf("%d",&newnode->data);
current=head;
if(pos==1)
{
newnode->next=head;
head=newnode;
return;
}
else{
for(int i=1;i<pos-1;i++)
{
current=current->next;
}
newnode->next=current->next;
current->next=newnode;
}
return;}

void delete()
{
    printf("Enter the element to Delete");
    int num;
    scanf("%d",&num);
    current=head;
    if(current!=NULL&&current->data==num)
    {
        head=current->next;
        free(current);
        return;
    }
    struct node *prev=NULL;
    while(current!=NULL&&current->data!=num)
    {
        prev=current;
        current=current->next;
    }
    if(current==NULL)
    {
        printf("Element not found");
        return;

    }
    prev->next=current->next;
    free(current);
    return;



}
void main()
{
int op=0;
while(op!=6)
{
    printf("\nEnter an option:\t1.Create\t2.Display\t3.Insert\t4.Delete\t5.Exit\n");
    scanf("%d",&op);
    switch(op)
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
        delete();
        break;
        case 5:
        op=5;
        break;
        default:
        printf("Enter a valid operator1");
    
    }
}


}


    