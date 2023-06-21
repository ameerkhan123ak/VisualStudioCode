#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    void findCombination(vector<int> &nums,int k,vector<int> &combination,vector<vector<int>> &ans)
    {
        if(k==0){
            ans.push_back(combination);
            return;
        }
        if(k<=0)
        {
            return;
        }
        for (int i = 0; i < nums.size();i++)
        {
            combination.push_back(nums[i]);
            findCombination(nums, k-nums[i], combination, ans);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &nums,int k)
    {
        vector<int> combination;
        vector<vector<int>> ans;
        findCombination(nums, k, combination, ans);
        return ans;
    }
};
int main()
{
    int k = 60;
    vector<int> v = {12, 3, 5};
    Solution s;
    vector<vector<int>> ans = s.combinationSum(v, k);
    for(auto i: ans)
    {
        for(auto j:i)
        {
            cout << j << " + ";
        }
        cout <<" = "<<k<< endl;
    }
}
