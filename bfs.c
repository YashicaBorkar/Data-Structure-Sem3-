#include<stdio.h>

int adj[10][10]={0}, visited[10]={0}, n;

void bfs(int x)
{
    int q[20], f = -1, r = -1, i, nd;

    visited[x] = 1;
    q[++r] = x;

    while(f != r)
    {
        nd = q[++f];
        printf("\t%d", nd);
        for(i = 0; i < n; i++)
        {
            if(adj[nd][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q[++r] = i;
            }
        }
    }
}

int main()
{
    int i, e, v1, v2, node;

    printf("\nEnter number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter number of edges: ");
    scanf("%d", &e);

    for(i = 0; i < e; i++)
    {
        printf("\nEnter edge: ");
        scanf("%d %d", &v1, &v2);
        adj[v1][v2] = adj[v2][v1] = 1;
    }

    printf("\nEnter starting node: ");
    scanf("%d", &node);

    printf("\nBFS Sequence: ");
    bfs(node);

    return 0;
}
