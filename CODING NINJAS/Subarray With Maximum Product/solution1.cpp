#include<bits/stdc++.h>
using namespace std;

int maximumProduct(int n,int arr[])
{
    int prefix=1,suffix=1;
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
        prefix = prefix * arr[i];
        suffix = suffix * arr[n-i-1];
        ans = max(ans,max(prefix,suffix));
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int maxValue=INT_MIN;
    int prod=1;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<maximumProduct(n,arr);
}