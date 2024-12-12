#include <stdio.h>
#include <stdlib.h>
#define max 100
void BFS(int graph[][max], int num)
{
    int visited[num], queue[num];
    int front = 0, rear = 0;
    for (int i = 0; i < num; i++)
        visited[i] = 0;
    int s = 0;
    visited[s] = 1;
    queue[rear++] = s;
    while (front < rear)
    {
        s=queue[front++];
        for (int i = 0; i < num; i++)
        {
            if (graph[s][i] == 1)
            {
                if (visited[i] == 0)
                {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
        }
        
    }
        for (int i = 0; i <num; i++)
        {
            if(visited[i]==1)
            printf("%d\t",i);
        }
        
}
    void main()
    {
        
        int num, i = 0, j, k, flag = 1;
        int graph[max][max] = {0};
        printf("\nEnter the number of vertices in graph:");
        scanf("%d", &num);
        int maxEdge = (num * (num - 1)) / 2;
        while (i < maxEdge)
        {
            printf("\nEnter the vertices connected by edge (-1 to exit ): ");
            scanf("%d", &j);
            if(j==-1)
            break;
            scanf("%d", &k);
            if(j>=num || k>=num)
            {
                printf("Please enter the vertices b/w 0 and %d",num);
                continue;
            }
            if(j==k)
            {
                printf("Please enter two different vertices");
                continue;
            }
            graph[j][k] = graph[k][j] = 1;
            i++;
        }
        BFS(graph, num);
    }