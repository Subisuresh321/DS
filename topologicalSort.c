#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max 100

int A[max][max] = {0};
int sorted[max] = {0};

void topSort(int A[][max], int n)
{
    int j = 0;
    while (j < n)
    {
        int flag = 1;
        if (sorted[j]!=1)
        {
            for (int i = 0; i < n; i++)
            {
                if (A[i][j] != 0)
                    flag = 0;
            }
            if (flag==1)
            {
                sorted[j] = 1;
                printf("%d",j);
                for (int k = 0; k < n; k++)
                    A[j][k] = 0;
                j = 0;
            }
            else
            j++;
        }
        else
        {
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(!sorted[i]){
        printf("\nThe given graph contains cycle!!!!...Cannnot be Sorted Further");
        break;
        }

    }
}

void main()
{
    int n;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("\nEnter the adjaceny matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                A[i][j] = 0;
            else
            {
                printf("graph[%d][%d] : ", i, j);
                scanf("%d", &A[i][j]);
            }
        }
    }
    topSort(A, n);
}