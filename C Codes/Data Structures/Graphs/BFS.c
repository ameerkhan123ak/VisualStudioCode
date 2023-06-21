#include<stdio.h>
#include<stdlib.h>
#define MAXVERTICES 50

typedef struct Graph
{
    int V;
    int adj[MAXVERTICES][MAXVERTICES];
}Graph;

Graph* createGraph(int V)
{
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            g->adj[i][j] = 0;
        }
    }
    return g;
}
void addEdge(Graph* g,int u,int v)
{
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}
void DepthFirstSearch(Graph* g,int v)
{
    int front=0,rear=0;
    int queue[g->V];
    int visited[g->V];
    for(int i=0;i<g->V;i++) visited[i] = 0;
    visited[v] = 1;
    queue[rear++] = v;
    while(front != rear)
    {
        int vertex = queue[front++];
        printf("%d ",vertex);
        for(int i=0;i<g->V;i++)
        {
            if(!visited[i] && g->adj[vertex][i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
void printAdjMatrix(Graph* g)
{
    for(int i=0;i<g->V;i++)
    {
        for(int j=0;j<g->V;j++)
        {
            printf("%d ",g->adj[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n = 5;
    Graph* g = createGraph(n);
    addEdge(g,0,1);
    addEdge(g,0,4);
    addEdge(g,1,2);
    addEdge(g,1,3);
    addEdge(g,1,4);
    addEdge(g,2,3);
    addEdge(g,3,4);
    DepthFirstSearch(g,0);
}