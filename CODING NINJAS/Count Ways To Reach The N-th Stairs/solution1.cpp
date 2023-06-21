#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int countDistinctWays(long long n) {
    vector<long long> dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    return dp[n];
}
int main()
{
    
    int n;
    cin>>n;
    cout<<countDistinctWays(n);
}