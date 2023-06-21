#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public: 
    void dfs(int row,int col,vector<vector<int>> &visited,vector<vector<char>> mat)
    {
        visited[row][col]= 1;
        int n = mat.size();
        int m = mat[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && mat[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,visited,mat);
            }
        }
    }
    vector<vector<char>> fill(int n,int m,vector<vector<char>> mat)
    {
        int l = mat.size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++) //for first ans last rows
        {
            if(!visited[0][i] && mat[0][i]=='O') dfs(0,i,visited,mat);
            if(!visited[n-1][i] && mat[n-1][i]=='O') dfs(n-1,i,visited,mat);
        }
        for(int i=0;i<n;i++) //for first and last column
        {
            if(!visited[i][0] && mat[i][0]=='O') dfs(i,0,visited,mat);
            if(!visited[i][m-1] && mat[i][m-1]=='O') dfs(i,n-1,visited,mat);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && mat[i][j]=='O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};
int main()
{
    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}};

    Solution s;
    int n=5,m=4;
    vector<vector<char>> ans = s.fill(n,m,mat);
    for(auto i: ans)
    {
        for(auto j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }     
}