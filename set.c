#include<stdio.h>
#include<stdlib.h>
void set_union(int arr1[],int arr2[],int limit)
{
    printf("\n The Union is:{");
    for(int i=0;i<limit;i++)
    {
        if(arr1[i] || arr2[i]==1)
        printf("%d,",i);
    }
    printf("}");
}
void set_intersection(int arr1[],int arr2[],int limit)
{
    printf("\n The Intersection is:{");
    for(int i=0;i<limit;i++)
    {
        if(arr1[i] && arr2[i]==1)
        printf("%d,",i);
    }
    printf("}");
}

void set_display(int arr[],int limit)
{
    printf("\n The Set is:{");
    for(int i=0;i<limit;i++)
    if(arr[i]==1)
    printf("%d",arr[i]);
    printf("}");
}

void main()
{
    int limit,num1,num2;
    printf("\nEnter the number of elements in universal set:");
    scanf("%d",&limit);
    int arr1[limit],arr2[limit];

    for(int i=0;i<limit;i++)
    {
        arr1[i]=arr2[i]=0;
    }
    
    printf("\nEnter the elements of first subset:");
    scanf("%d",&num1);
    int i=0;
    while(i<num1)
    {
        int data;
        printf("\nEnter the Element:");
        scanf("%d",&data);
        if(data>=limit || data<0)
        printf("\nEnter a valid element");
        else
        {
            arr1[data]=1;
            i++;
        }

    }
    
    printf("\nEnter the elements of second subset:");
    scanf("%d",&num2);
    i=0;
    while(i<num2)
    {
        int data;
        printf("\nEnter the Element:");
        scanf("%d",&data);
        if(data>=limit || data<0)
        printf("\nEnter a valid element");
        else
        {
            arr2[data]=1;
            i++;
        }

    }
set_display(arr1,limit);
set_display(arr2,limit);
set_union(arr1,arr2,limit);
set_intersection(arr1,arr2,limit);
}