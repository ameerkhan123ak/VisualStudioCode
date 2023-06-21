#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void DFS(int node,vector<int> &visited,stack<int> &s,vector<int> adj[])
    {
        visited[node]=1;
        for(auto i: adj[node])
        {
            if(!visited[i])
            {
                DFS(i,visited,s,adj);
            }
        }
        s.push(node);
    }
    vector<int> topologicalSorting(int V,vector<int> adj[])
    {
        vector<int> visited(V,0);
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFS(i,visited,s,adj);
            }
        }
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
int main()
{
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int V=6;
    Solution s;
    vector<int> ans = s.topologicalSorting(V,adj);
    for(auto i: ans) cout<<i<<" ";
}