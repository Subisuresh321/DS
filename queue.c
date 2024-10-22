#include<stdio.h>
#include<stdlib.h>

void push(int arr[],int num,int *rear,int *front)
{
if (*rear >= num - 1) {
        printf("Queue is Full\n");
        return;
    }
    if (*rear == -1) {
        *rear = *front = 0;
    } else {
        (*rear)++;
    }
    printf("Enter the data: ");
    scanf("%d", &arr[*rear]);
}

void pop(int arr[],int *rear,int *front)
{
if(*rear==-1 || *front>*rear)
{
    printf("Queue is Empty");
        return;
}
printf("Popping element: %d\n", arr[*front]);
(*front)++;
return;
}

void display(int arr[],int *rear,int *front)
{
    if(*rear==-1||*front>*rear)
    {
        printf("Queue is Empty");
        return;
    }
    else
    {
        for(int i=*front;i<=*rear;i++)
        printf("%d",arr[i]);
        printf("\n");
    }
}
int main() {
    int front = -1, rear = -1, num;
    printf("Enter the number of elements: ");
    scanf("%d", &num);
    int arr[num];
    int op = 0;
    printf("Hai");
    while (op != 5) {
        printf("\nEnter an option\t1.Insert\t3.Display\t4.Delete\t5.Exit:\n");
        scanf("%d", &op);
        switch (op) {
            case 1: 
                push(arr, num, &rear, &front); 
                break;
            case 3: 
                display(arr, &rear, &front); 
                break;
            case 4: 
                pop(arr, &rear, &front); 
                break;
            case 5: 
                printf("Exiting...\n");
                break;
            default: 
                printf("Enter a valid operator\n");
        }
    }
    return 0;
}
