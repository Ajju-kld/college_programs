#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 10
#define INF INT_MAX

int n;
int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES][MAX_NODES];

void read_input(const char *filename)
{
    FILE *fp;
    int i, j, u, v, w, m;

    fp = fopen(filename, "r");

    if (!fp)
    {
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    fscanf(fp, "%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
            dist[i][j] = INF;
        }
    }

    for (i = 0; i < m; i++)
    {
        fscanf(fp, "%d %d %d", &u, &v, &w);
        graph[u][v] = graph[v][u] = 1;
        dist[u][v] = dist[v][u] = w;
    }

    fclose(fp);
}

void link_state_routing(int source)
{
    int i, j, k, min_dist, next_hop, visited[MAX_NODES], path[MAX_NODES], cost[MAX_NODES];

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        path[i] = -1;
        cost[i] = INF;
    }

    cost[source] = 0;

    for (i = 0; i < n; i++)
    {
        min_dist = INF;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] && cost[j] < min_dist)
            {
                min_dist = cost[j];
                next_hop = j;
            }
        }

        visited[next_hop] = 1;

        for (k = 0; k < n; k++)
        {
            if (!visited[k] && graph[next_hop][k])
            {
                if (cost[next_hop] + dist[next_hop][k] < cost[k])
                {
                    cost[k] = cost[next_hop] + dist[next_hop][k];
                    path[k] = next_hop;
                }
            }
        }
    }

    printf("Routing table for node %d:\n", source);

    for (i = 0; i < n; i++)
    {
        if (i == source)
            continue;

        printf("To node %d: ", i);

        j = i;
        while (j != -1)
        {
            printf("%d ", j);
            j = path[j];
        }

        printf("Distance: %d\n", cost[i]);
    }
}

int main()
{
    char filename[50];
    int source;

    printf("Enter the input filename: ");
    scanf("%s", filename);

    read_input(filename);

    printf("Enter the source node: ");
    scanf("%d", &source);

    link_state_routing(source);

    return 0;
}
