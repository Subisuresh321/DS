#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *newnode,*top=NULL;

void push();
void create()
{
int num;
printf("Enter the intial number of elements in stack\n");
scanf("%d",&num);
for(int i=0;i<num;i++)
push();
return;
}

void push()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: \n");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
    return;
}

void pop()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else{
        top=top->next;
        return;
    }
}

void display()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else{
        struct node *temp=top;
    while (temp!=NULL)
    {
        printf("%d \t",temp->data);
        temp=temp->next;
    }
    return;
    }
}

void peek()
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else{
    printf("%d is top\t",top->data);
    }
}

void main()
{
    int op=0;
    while (op!=6)
    {
    printf("\nEnter any operation 1.Create 2.Display 3.Push 4.Pop 5.Peek 6.Exit \n");
    scanf("%d",&op);
        switch (op)
        {
        case 1:create();
            break;
        case 2:display();
            break;
        case 3:push();
            break;
        case 4:pop();
            break;
        case 5:peek();
            break;
        case 6: break;
        default: printf("Enter any valid operation!\n");
            break;
        }
    }
    

}