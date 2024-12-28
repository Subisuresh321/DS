#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max 10
int A[max][max] = {0};

void Union(int minU, int minV, int parent[], int size[]);
int Find(int V, int parent[]);
void Union(int minU, int minV, int parent[], int size[]);

void prims(int A[][max], int n)
{
    int min, minV, minU, minVP, minUP, edgeCount = 1;
    int parent[n], size[n], visited[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
        visited[i] = 0;
    }
    visited[0] = 1;
    while (edgeCount < n)
    {
        min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (A[i][j] < min)
                    {
                        min = A[i][j];
                        minU = i;
                        minV = j;
                    }
                }
            }
        }

        if (min == INT_MAX)
            break;
        A[minU][minV] = A[minV][minU] = INT_MAX;
        minUP = Find(minU, parent);
        minVP = Find(minV, parent);
        if (minUP != minVP)
        {
            printf("%d->", min);
            Union(minUP, minVP, parent, size);
            visited[minV] = 1;
            edgeCount++;
        }
    }
}

int Find(int V, int parent[])
{
    if (parent[V] == V)
        return V;
    else
    {
        parent[V] = Find(parent[V], parent); // path compression
        return parent[V];
    }
}

void Union(int minUP, int minVP, int parent[], int size[])
{
    if (size[minUP] < size[minVP])
    {
        parent[minVP] = minUP;
        size[minUP] += size[minVP];
    }
    else
    {
        parent[minUP] = minVP;
        size[minVP] += size[minUP];
    }
}

void main()
{
    int n;
    printf("\nEnter the number of vertices in graph:");
    scanf("%d", &n);
    printf("Enter the adjacency matrix(weight) : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                A[i][j] = 0;
            else
            {
                printf("A[%d][%d] : ", i, j);
                scanf("%d", &A[i][j]);
            }
            if (A[i][j] == 0)
                A[i][j] = INT_MAX;
        }
    }
    prims(A, n);
}