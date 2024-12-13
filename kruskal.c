#include<stdio.h>
#include<stdlib.h>
#define max 100
int graph[max][max]={0};

void main()
{
    int num,i=0,j,k,weight;
    printf("\nEnter the number of vertices in graph:");
    scanf("%d", &num);
    int queue[num],visited[num];
    for (int i = 0; i < num; i++)
        visited[i] = 0;
    int maxEdge = (num * (num - 1)) / 2;
    int weightarr[maxEdge];
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
        printf("\nEnter the weight of Edge:");
        scanf("%d",&weight);
        graph[j][k] = graph[k][j] = weight;
        weightarr[i]=weight;
        i++;
    }
    
    kruskalAlg();
}