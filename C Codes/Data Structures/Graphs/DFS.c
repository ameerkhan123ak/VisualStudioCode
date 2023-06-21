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
void dfs(Graph* g,int visited[],int v)
{
    visited[v] = 1;
    printf("%d ",v);
    for(int i=0;i<g->V;i++)
    {
        int vertex = g->adj[v][i];
        if(!visited[i] && vertex)
        {
            visited[i] = 1;
            dfs(g,visited,i);
        }
    }
}
void DepthFirstSearch(Graph* g,int v)
{
    int visited[g->V];
    for(int i=0;i<g->V;i++) visited[i] = 0; 
    dfs(g,visited,v);
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