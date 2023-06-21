#include<bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    void solve(string digits,int index,string output,vector<string> &ans,string mapping[])
    {
        if(index >= digits.length())
        {
            ans.push_back(output);
            return;
        } 
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i=0;i<value.length();i++)
        {
            output.push_back(value[i]);
            solve(digits,index+1,output,ans,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombination(string digits)
    {
        int index=0;
        string output="";
        vector<string> ans;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqr","stu","wxyz"};
        solve(digits,index,output,ans,mapping);
        return ans;
    }
};
int main()
{
    string s;
    cin>>s;
    Solution sol;
    vector<string> ans = sol.letterCombination(s);
    for(auto i:ans) cout<<i<<endl;
}