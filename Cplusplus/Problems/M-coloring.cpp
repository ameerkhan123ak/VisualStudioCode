#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool isSafe(int node,int color[],bool graph[4][4],int n,int col)
    {
        for(int k=0;k<n;k++)
        {
            if(k!=node && graph[k][node]==1 && color[k]==col)
            return false;
        }
        return true;
    }
    bool solve(int node,int color[],int M,int N,bool graph[4][4])
    {
        if(node==N) return true;
        
        for(int i=1;i<=M;i++)
        {
            if(isSafe(node,color,graph,N,i))
            {
                color[node] = i;
                if(solve(node+1,color,M,N,graph)) 
                return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[4][4],int M,int N)
    {
        int color[N] = {0};
        if(solve(0,color,M,N,graph)) return true;
        return false;
    }
};
int main()
{
    bool graph[4][4] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
  
    Solution s;
    if(s.graphColoring(graph,3,4)) cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;

}
//time complexity: (N^M)
//space complexity: O(n) + O(n) = O(n)