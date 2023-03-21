#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_NODES 10
#define MAX_NEIGHBORS 5
#define INFINITY 999

int n;                                      // Total number of nodes in the network
int adjacency_matrix[MAX_NODES][MAX_NODES]; // Adjacency matrix to store the network topology
int distance_vector[MAX_NODES];             // Distance vector to store the current distances to all nodes
bool visited[MAX_NODES];                    // To keep track of nodes that have been processed

void init_adjacency_matrix()
{
    memset(adjacency_matrix, 0, sizeof(adjacency_matrix));
}

void init_distance_vector()
{
    int i;
    for (i = 1; i <=n; i++)
    {
        distance_vector[i] = INFINITY;
    }
}

void init_visited()
{
    memset(visited, false, sizeof(visited));
}



void dijkstra(int source)
{
    int i, j;

    int current_node;
    int min_distance;

    init_distance_vector();
    distance_vector[source] = 0;

    for (i = 1; i <=n; i++)
    {
        init_visited();
        current_node = -1;
        min_distance = INFINITY;
        
        // Find the node with the minimum distance that has not been processed
        for (j = 1; j <= n; j++)
        {
            if (!visited[j] && distance_vector[j] < min_distance)
            {
                current_node = j;
                min_distance = distance_vector[j];
            }
        }

        // If there are no more nodes to process, break the loop
        if (current_node == -1)
        {
            break;
        }

        visited[current_node] = true;

        // Update the distances to all neighbors of the current node
        for (j = 1; j <= n; j++)
        {   
            if (!visited[j])
            {
                int new_distance = distance_vector[current_node] + adjacency_matrix[current_node][j];
                if (new_distance < distance_vector[j])
                {
                    distance_vector[j] = new_distance;
                }
            }
        }
    }
}

int main()
{
    int i, j;
FILE *fp;
fp=fopen("input.txt","r");
    printf("Enter the number of nodes in the network: ");
    fscanf(fp,"%d", &n);

    init_adjacency_matrix();

    printf("Enter the adjacency matrix (999 for infinity):\n");
    for (i = 1; i <=n; i++)
    {     
        for (j=1; j <=n; j++)

        {
            if(i==j)
                continue;
               printf("%d --> %d:\t",i+1,j+1);
            fscanf(fp,"%d", &adjacency_matrix[i][j]);
        }
    }
    int source;
    printf("Enter the source node: ");
    fscanf(fp,"%d", &source);

    dijkstra(source);

    printf("The distance vector for the network is:\n");
    for (i = 1; i <=n; i++)
    {

        if (i == source)
            continue;
        printf("the cost of the shortest path from router %d to %d is %d\n",source,i,distance_vector[i]);
    }
    printf("\n");

    return 0;
}