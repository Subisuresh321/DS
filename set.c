#include<stdio.h>
#include<stdlib.h>
void set_union(int arr1[],int arr2[],int u[],int limit)
{
    printf("\n The Union is:{");
    for(int i=0;i<limit;i++)
    {
        if(arr1[i]==1 || arr2[i]==1)
        printf("%d,",u[i]);
    }
    printf("}");
}
void set_intersection(int arr1[],int arr2[],int u[],int limit)
{
    printf("\n The Intersection is:{");
    for(int i=0;i<limit;i++)
    {
        if(arr1[i]==1 && arr2[i]==1)
        printf("%d,",u[i]);
    }
    printf("}");
}

void set_display(int arr[],int limit)
{
    printf("\n The Set is:{");
    for(int i=0;i<limit;i++)
    printf("%d,",arr[i]);
    printf("}");
}
// void set_display(int arr[],int limit)
// {
//     printf("\n The Set is:{");
//     for(int i=0;i<limit;i++)
//     if(arr[i]==1)
//     printf("%d",arr[i]);
//     printf("}");
// }

int isPresent(int data,int u[],int limit)
{
    int i=0;
    while (i<limit)
    {
        if(data==u[i])
        return i;
        i++;
    }
    return -1; 
}
void main()
{
    int limit,num1,num2;
    printf("\nEnter the number of elements in universal set:");
    scanf("%d",&limit);
    int u[limit];
    printf("\nEnter the elements of universal set:");
    for(int i=0;i<limit;i++){
    printf("\nEnter the Element:");    
    scanf("%d",&u[i]);
    }
    set_display(u,limit);
    int arr1[limit],arr2[limit];

    for(int i=0;i<limit;i++)
    {
        arr1[i]=arr2[i]=0;
    }
    
    printf("\nEnter the elements of first subset(less than %d):",limit);
    scanf("%d",&num1);
    int i=0;
    while(i<num1)
    {
        int k,data;
        printf("\nEnter the Element:");
        scanf("%d",&data);
        k=isPresent(data,u,limit);
        if(k!=-1)
        {
            arr1[k]=1;
            i++;
        }
        else
        {
            printf("\nEnter a valid element which is a subset of Universal Set");
        }

    }
    
    printf("\nEnter the elements of second subset(less than %d):",limit);
    scanf("%d",&num2);
    i=0;
    while(i<num2)
    {
        int k,data;
        printf("\nEnter the Element:");
        scanf("%d",&data);
        k=isPresent(data,u,limit);
        if(k!=-1)
        {
            arr2[k]=1;
            i++;
        }
        else
        {
            printf("\nEnter a valid element which is a subset of Universal Set");
        }

    }
set_display(arr1,limit);
set_display(arr2,limit);
set_union(arr1,arr2,u,limit);
set_intersection(arr1,arr2,u,limit);
}