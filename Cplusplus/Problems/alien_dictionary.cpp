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
    vector<int> topologicalSort(int V,vector<int> adj[])
    {
        vector<int> visited(V,0);
        stack<int> s;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFS(i,visited,s,adj);
            }
        }
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
    string findOrder(string dict[],int N,int K)
    {
        vector<int> adj[K];
        for(int i=0;i<N-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int ptr=0;ptr<len;ptr++)
            {
                if(s1[ptr]!=s2[ptr])
                {
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        vector<int> topo = topologicalSort(K,adj);
            string ans = "";
        for(auto i: topo)
        {
            ans = ans + char(i+'a');
        }
        return ans;
    }
};
int main()
{
    int N=5,K=4;
    string dict[] = {"baa","abcd","abca","cab","cad"};
    Solution s;
    string ans  = s.findOrder(dict,N,K);
    for(auto ch: ans) cout<<ch<<" ";
}