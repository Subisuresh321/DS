#include <stdio.h>
#include <stdlib.h>
int isFull(int arr[], int *rear, int *front, int num)
{
    if ((*rear + 1) % num == *front)
    {
        printf("The queue is FULL");
        return 0;
    }
    return 1;
}

int isEmpty(int arr[], int *rear, int *front, int num)
{
    if (*rear == -1 && *front == -1)
    {
        printf("The queue is Empty");
        return 0;
    }
    return 1;
}

void push(int arr[], int *rear, int *front, int num)
{
    if (isFull(arr, rear, front, num))
    {
        if (*front == -1)
            *front = *rear = 0;
        else
            *rear = (*rear + 1) % num;
        printf("Enter the number:");
        scanf("%d", &arr[*rear]);
    }
    return;
}

void pop(int arr[], int *rear, int *front, int num)
{
    int temp;
    if (isEmpty(arr, rear, front, num))
    {
        if (*front == *rear)
            *front = *rear = -1;
        else
            *front = (*front + 1) % num;
    }
    return;
}

void display(int arr[], int *rear, int *front, int num)
{
    if (isEmpty(arr, rear, front, num))
    {
        int temp = *front;
        while (temp != *rear)
        {
            printf("%d\t", arr[temp]);
            temp = (temp + 1) % num;
        }
        printf("%d\t", arr[temp]); 
    }
    return;
}
int main()
{
    int front = -1, rear = -1, num;
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    int arr[num];
    int op = 0;
    while (op != 4)
    {
        printf("\nEnter an option\t1.Insert\t2.Display\t3.Delete\t4.Exit:\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            push(arr, &rear, &front, num);
            break;
        case 2:
            display(arr, &rear, &front, num);
            break;
        case 3:
            pop(arr, &rear, &front, num);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Enter a valid operator\n");
        }
    }
    return 0;
}
