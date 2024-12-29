#include<stdio.h>
#include<stdlib.h>

void main()
{
    int num1,num2,num3;
    printf("Enter the number of elements in both array:\n");
    scanf("%d",&num1);
    scanf("%d",&num2);
    num3=num1+num2;
    int arr1[num1],arr2[num2];
    int arr3[num3];
    printf("enter the elements of first array: ");
    for(int i=0;i<num1;i++)
    scanf("%d",&arr1[i]);
    printf("enter the elements second array: ");
    for(int i=0;i<num2;i++)
    scanf("%d",&arr2[i]);

    for(int i=0;i<num3;i++)
    {
        if(i<num1)
        arr3[i]=arr1[i];
        else
        arr3[i]=arr2[i-num1];
    }
    
    
     printf("The elements of merged array: ");
    for(int i=0;i<num3;i++)
    printf("%d\t",arr3[i]);

}
