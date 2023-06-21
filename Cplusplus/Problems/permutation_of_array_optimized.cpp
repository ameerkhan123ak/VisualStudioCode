#include<bits/stdc++.h>
using namespace std;
void permutation(vector<int> &arr,int start,int end,vector<vector<int>> &ans)
{
   if(start==end)
   {
       ans.push_back(arr);
       return;
   }
   for(int i=start;i<=end;i++)
   {
      swap(arr[start],arr[i]);
      permutation(arr,start+1,end,ans);
      swap(arr[start],arr[i]);
   }
}
int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    permutation(arr,0,arr.size()-1,ans);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

/*
Time complexity: n! * n
Space complexity: 
*/