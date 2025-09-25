#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 99999

int n;
int minDist(int dist[], int visited[])
{
    int min = INF, minIndex = -1;
    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("->%d", j + 1);
}

void dijkstra(int graph[50][50], int src)
{
    int dist[50];
    int visited[50];
    int parent[50];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;
    for (int c = 0; c < n - 1; c++)
    {
        int u = minDist(dist, visited);
        visited[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nSource\tDestination\tCost\tPath\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t", src + 1, i + 1);
        if (dist[i] == INF)
            printf("INF\tNo Path\n");
        else
        {
            printf("%d\t", dist[i]);
            if (i == src)
                printf("-\n");
            else
            {
                printf("%d", src + 1);
                printPath(parent, i);
                printf("\n");
            }
        }
    }
}

int main()
{
    FILE *fp;
    int graph[50][50];
    int src;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    fp = fopen("inDiAdjMat1.dat", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &graph[i][j]);

    fclose(fp);

    printf("Enter the Source Vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src - 1);

    return 0;
}
