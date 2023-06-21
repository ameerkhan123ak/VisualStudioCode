#include<bits/stdc++.h>
using namespace std;

int fun(int index,vector<int> &nums)
{
    if(index==0) return nums[0];
    if(index<0) return 0;

    int pick = nums[index] + fun(index-2,nums);
    int notPick = 0 + fun(index-1,nums);
    
    return max(pick,notPick);
} 
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    return fun(n-1,nums);
}
int main()
{
    vector<int> nums{1,2,3};
    int ans = maximumNonAdjacentSum(nums);
    cout<<ans;
}