#include<iostream>
#include<vector>
#include<queue>
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
        adj[v].push_back(u);
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
    void BreadthFirstSearch(int v)
    {
        queue<int> q;
        q.push(v);
        bool visited[V] = {false};
        visited[v] = true;
        while(!q.empty())
        {
            int vertex = q.front();
            q.pop();
            cout<<vertex<<" ";
            for(auto i: adj[vertex])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.printAdjList(0);
    g.BreadthFirstSearch(0);
}