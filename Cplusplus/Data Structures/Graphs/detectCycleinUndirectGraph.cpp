#include<iostream>
#include<vector>
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
    bool detectCycle(int v,bool visited[],int parent)
    {
        visited[v] = true;
        for(auto i: adj[v])
        {
            if(!visited[i])
            {
                if(detectCycle(i,visited,v)) return true;
            }
            else if(parent!=i) return true;
        }
        return false;
    }
    bool isCyclic()
    {
        bool visited[V];
        for(int i=0;i<V;i++) visited[i] = false;
        for(int i=0;i<V;i++)
        {
            if(!visited[i] && detectCycle(i,visited,-1))
            return true;
        }
        return false;
    }
};
int main()
{
    Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.isCyclic() ? cout << "Graph contains cycle\n"
				: cout << "Graph doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.isCyclic() ? cout << "Graph contains cycle\n"
				: cout << "Graph doesn't contain cycle\n";
}