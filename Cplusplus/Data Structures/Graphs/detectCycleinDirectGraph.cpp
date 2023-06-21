#include<iostream>
#include<vector>
#include<cstring>
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
        //adj[v].push_back(u);
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
    bool DetectCycle(int v,bool visited[],bool *recStack)
    {
        if(!visited[v])
        {
            visited[v] = true;
            recStack[v] = true;
        }
        for(auto i: adj[v])
        {
            if(!visited[i] && DetectCycle(i,visited,recStack))
            return true;
            else if(recStack[i])
            return true;
        }
        recStack[v] = false;
        return false;
     }
    bool isCyclic()
    {
        bool visited[V];
        bool recstack[V];
        for(int i=0;i<V;i++)
        {
            visited[i] = false;
            recstack[i] = false;
        }
        for(int i=0;i<V;i++)
        {
            if(!visited[i] && DetectCycle(i,visited,recstack))
            return true;
        }
        return false;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    //g.printAdjList(0);
   if(g.isCyclic()) cout<<"Cycle";
   else cout<<"Not Cycle";
}