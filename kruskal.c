#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max 100
int A[max][max] = {0};

void kruskal(int A[][max],int n)
{
    int min=INT_MAX,minV,minU;
    for(int i=0;i<n;i++)
    {
       for (int j = 0; j < n; j++) 
       {
            if(A[i][j] < min && A[i][j] != INT_MAX)
            {
            min=A[i][j];
            minU=i;
            minV=j;
            }
       }
    }
    if(unionFind(minU,minV))
    {

    }
    
}

int unionFind(minU,minV)
{

}
void main()
{
    int n, i = 0, j, k, weight;
    printf("\nEnter the number of vertices in graph:");
    scanf("%d", &n);
    printf("Enter the adjacency matrix(weight) : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d] : ", i, j);
            scanf("%d", &A[i][j]);
            if (A[i][j] == 0)
                A[i][j] = INT_MAX;
        }
    }
    kruskal(A,n);
}