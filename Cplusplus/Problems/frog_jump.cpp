#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    int frogJumps(int n,vector<int> &heights)
    {
        vector<int> dp(n,0);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            int a = dp[i-1] + abs(heights[i-1] - heights[i]);
            int b = INT_MAX;
            if(i>1)
            b = dp[i-2] + abs(heights[i-2] - heights[i]);

            dp[i] = min(a,b);
        }
        return dp[n-1];
    }
};
int main()
{
    vector<int> heights = {10,20,30,10};
    Solution s;
    cout<<s.frogJumps(4,heights);
}