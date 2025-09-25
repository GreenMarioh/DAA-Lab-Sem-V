#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int minKey(int V, int key[], bool mstSet[])
{
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int V, int parent[], int graph[V][V])
{
    int mst[V][V];
    int totalCost = 0;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            mst[i][j] = 0;

    for (int i = 1; i < V; i++)
    {
        int u = parent[i];
        int v = i;
        int w = graph[i][parent[i]];
        mst[u][v] = w;
        mst[v][u] = w;
        totalCost += w;
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", mst[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Weight of the Spanning Tree: %d\n", totalCost);
}

/*int printMST(int V, int parent[], int graph[V][V]){
    printf("Edge \t Weight: \n");
    for(int i  =0; i < V; i++){
        printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]);
    }
}*/

void primMST(int V, int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;

    parent[0] = -1;

    for (int c = 0; c < V - 1; c++)
    {
        int u = minKey(V, key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(V, parent, graph);
}

/*int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;


    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;
    }

    primMST(n, graph);

    return 0;
}*/

int main()
{
    FILE *fp = fopen("inUnAdjMat.dat", "r");
    if (!fp)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n); // read number of vertices

    int graph[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }
    fclose(fp);

    int start;
    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);

    primMST(n, graph);

    return 0;
}
