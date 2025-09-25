#include <stdio.h>
#include <stdlib.h>

int comparator(const void *p1, const void *p2)
{
    return ((int *)p1)[2] - ((int *)p2)[2];
}

void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component)
{
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[], int n)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int kruskalAlgo(int n, int e, int edge[e][3])
{
    qsort(edge, e, sizeof(edge[0]), comparator);
    int parent[n + 1], rank[n + 1];
    makeSet(parent, rank, n);
    int minCost = 0;
    printf("Edge   Cost\n");
    for (int i = 0; i < e; i++)
    {
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];
        if (v1 != v2)
        {
            unionSet(v1, v2, parent, rank, n);
            printf("%d--%d    %d\n", edge[i][0], edge[i][1], wt);
            minCost += wt;
        }
    }
    printf("\nTotal Weight of the Spanning Tree: %d\n", minCost);
    return minCost;
}

int main()
{
    int n, e;
    scanf("%d %d", &n, &e);
    int edge[e][3];
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }
    kruskalAlgo(n, e, edge);
    return 0;
}
