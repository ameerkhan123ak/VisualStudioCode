#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    int V;
    vector<vector<int>> adj;
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
    }
    void printAdjList(int v)
    {
        for(int i=0;i<adj.size();i++)
        {
            cout<<i<<": ";
            for(auto j: adj[i])
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }   
    }
    void bfs(int v,vector<bool> &visited)
    {
        queue<int> q;
        q.push(v);
        visited[v] = true;
        while(!q.empty())
        {
            int vertex = q.front();
            q.pop();
            cout<<vertex<<" ";
            for(int i=0;i<adj[v].size();i++)
            {
                int adjVertex = adj[v][i];
                if(!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
            }
        }
    }
    void BreadthFirstSearch(int v)
    {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++) visited[i] = false;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                dfs(i,visited);
            }
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.DepthFirstSearch(0);
}