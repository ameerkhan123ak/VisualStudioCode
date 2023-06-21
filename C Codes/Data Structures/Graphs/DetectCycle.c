#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
}
bool detectCycle(Graph* g)
{
    for(int i=0;i<g->V;i++)
    {
        int count=0;
        for(int j=0;j<g->V;j++)
        {
            if(g->adj[j][i]==1) count++;
        }
        if(count>1) return true;
    }
    return false;
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
    bool x = detectCycle(g); printf("%d",x);
}