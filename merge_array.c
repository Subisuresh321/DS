#include<stdio.h>
#include<stdlib.h>

void main()
{
    int num1,num2,num3;
    printf("Enter the number of elements in both array");
    scanf("%d",&num1);
    scanf("%d",&num2);
    num3=num1+num2;
    int arr1[num1],arr2[num2];
    int arr3[num3];
    printf("enter the elements of first array");
    for(int i=0;i<num1;i++)
    scanf("%d",&arr1[i]);
    printf("enter the elements second array");
    for(int i=0;i<num2;i++)
    scanf("%d",&arr2[i]);

    for(int i=0;i<num1;i++)
    arr3[i]=arr1[i];
    for(int i=0;i<num2;i++)
    arr3[num1+i]=arr2[i];
    
    
     printf("enter the elements of merged array");
    for(int i=0;i<num3;i++)
    printf("%d\t",arr3[i]);

}
