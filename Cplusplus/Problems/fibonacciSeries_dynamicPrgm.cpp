#include<iostream>
#include<vector>
using namespace std;
int fibonacci_series(int n,vector<int> &dp)
{
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fibonacci_series(n-1,dp) + fibonacci_series(n-2,dp);
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    int ans = fibonacci_series(n,dp);
    cout<<ans;
}