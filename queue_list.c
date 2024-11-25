#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL, *newnode;
void enqueue();
void create()
{
    int num;
    printf("Enter the initial elements in queue\n");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
        enqueue();
    return;
}

void enqueue()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    if (rear == NULL)
    {
        front = rear = newnode;
        rear->next = NULL;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = NULL;
    }
    return;
}

void dequeue()
{
    if (front == NULL)
        printf("Queue is empty\n");
    else{
        struct node *temp=front;
        front = front->next;
        if(front==NULL) 
        rear=NULL;  // so that next enqueue works correctly after dequeuing all elements
        free(temp);
    }
        
    return;
}

void display()
{
    if (front == NULL)
        printf("Queue is empty\n");
    else
    {
        struct node *temp = front;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    return;
}

void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element: %d\n", front->data);
    }
}

void main()
{
    int op = 0;
    while (op != 6)
    {
        printf("\nEnter any operation 1.Create 2.Display 3.Enqueue 4.Dequeue 5.Peek 6.Exit \n");
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
            enqueue();
            break;
        case 4:
            dequeue();
            break;
        case 5:
            peek();
            break;
        case 6:
            exit(0);
        default:
            printf("Enter a valid operation!\n");
        }
    }
}