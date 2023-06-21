#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    int curr = -1;
    for(int i=1;i<n;i++)
    {
        int take = nums[i];
        if(i>1) take += prev2;

        int notTake = 0 + prev;

        curr = max(take,notTake);
        prev2 = prev;
        prev = curr;
    }
    return curr;
}
int main()
{
    vector<int> nums{1,2,4};
    int ans = maximumNonAdjacentSum(nums);
    cout<<ans;
}