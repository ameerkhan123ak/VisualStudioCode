#include<bits/stdc++.h>
using namespace std;

void print_combination(int n)
{
    vector<vector<char>> num=
    {{'\0'},
    {'\0'},
    {'a','b','c'},
    {'d','e','f'},
    {'g','h','i'},
    {'j','k','l'},
    {'m','n','o'},
    {'p','q','r','s'},
    {'t','u','v'},
    {'w','x','y','z'}};
   
    if(n<10)
    {
        for(int i=0;i<num[n].size();i++)
        cout<<num[n][i]<<" ";
    }
    else
    {
        string s = to_string(n);
        int n1 = s[0]-'0';
        int n2 = s[1]-'0';
        for(int i=0;i<num[n1].size();i++)
        {
            for(int j=0;j<num[n2].size();j++)
            {
                cout<<num[n1][i]<<num[n2][j]<<" ";
            }
        }
    }
   
}
int main()
{
    int n;
    cin>>n;
    print_combination(n);
}

