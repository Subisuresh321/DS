#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max 50
int adj[max][max] = {0};

void dijikstra(int adj[][max], int num)
{
    int dist[max], visited[max];
    int s, edgeCount = 1;
    for (int i = 0; i < num; i++)
    {
        visited[i] = 0;
        dist[i] = INT_MAX;
    }
    printf("\nEnter the source vertex: ");
    scanf("%d", &s);
    dist[s] = 0;
    while (edgeCount < num)
    {
        int min = INT_MAX;
        for (int i = 0; i < num; i++)
        {
            if (!visited[i] && min > dist[i])
            {
                min = dist[i];
                s = i;
            }
        }
        if(min==INT_MAX)
        break;
        visited[s] = 1;
        edgeCount++;

        for (int i = 0; i < num; i++)
        {
            if (adj[s][i] != INT_MAX)
            {
                if ((dist[s] + adj[s][i]) < dist[i])
                {
                    dist[i] = dist[s] + adj[s][i];
                }
            }
        }
    }
    printf("\nThe shortest path from source vertex : ");
    for (int i = 0; i < num; i++)
        printf("\nTo %d is %d", i, dist[i]);
}

void main()
{
    int num;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &num);
    printf("\nEnter the adjacency matrix(directed): ");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == j)
            {
                adj[i][j] = 0;
            }
            else
            {
                printf("\nAdj[%d][%d]: ", i, j);
                scanf("%d", &adj[i][j]);
            }
            if (adj[i][j] == 0)
            {
                adj[i][j] = INT_MAX;
            }
        }
    }
    dijikstra(adj, num);
}