#include <stdio.h>
#include <stdlib.h>
void BFS(int graph[][], int num)
{
    int visited[num], queue[num];
    int front = 0, rear = 0;
    for(int i=0;i<num;i++)
    visited[i]=0;
    int s=0;
    while(front<rear)
    {
        visited[s]=1;
        queue[rear++]=s;
        
    }

}
    void main()
    {
        int num, i = 0, j, k, flag;
        printf("\nEnter the number of vertices in graph:");
        scanf("%d", &num);
        int graph[num][num] = {0};
        int maxEdge = (num * (num - 1)) / 2;
        do
        {
            printf("\nEnter the vertices connected by edge: ");
            scanf("%d", &j);
            printf(",");
            scanf("%d", &k);
            graph[j][k] = graph[k][k] = 1;
            printf("\nDo you want to stop,then Enter 0 !!!");
            scanf("%d", &flag);
            if (!flag)
                break;
        } while (i < maxEdge);
        BFS(graph, num);
    }
