#include <stdio.h>
#include <stdlib.h>
#define max 100
int graph[max][max];
void dfs(int num,int visited[],int s)
{
    if(visited[s]==0)
    {
        visited[s]=1;
        for(int i=0;i<num;i++){
        if(graph[s][i]==1)
        dfs(num,visited,i);
        }
    }
}
void main()
{
    int num,i=0,j,k;
    printf("\nEnter the number of vertices in graph:");
    scanf("%d", &num);
    int queue[num],visited[num];
    for (int i = 0; i < num; i++)
        visited[i] = 0;
    int maxEdge = (num * (num - 1)) / 2;
    while (i < maxEdge)
    {
        printf("\nEnter the vertices connected by edge (-1 to exit ): ");
        scanf("%d", &j);
        if (j == -1)
            break;
        scanf("%d", &k);
        if (j >= num || k >= num)
        {
            printf("Please enter the vertices b/w 0 and %d", num);
            continue;
        }
        if (j == k)
        {
            printf("Please enter two different vertices");
            continue;
        }
        graph[j][k] = graph[k][j] = 1;
        i++;
    }
    int s=0;
    dfs(num,visited,s);
    for (int i = 0; i < num; i++)
        if(visited[i] == 1)
        printf("%d\t",i);
}