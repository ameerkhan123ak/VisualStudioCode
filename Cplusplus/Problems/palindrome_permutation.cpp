#include<bits/stdc++.h>
using namespace std;
bool palindromeString(string s) 
{
    unordered_map<char,int> m;
    for(int i=0;i<s.length();i++)
    {
        m[s[i]] = m[s[i]] + 1;
    }
    int odd=1;
    for(auto i: m)
    {
        if(i.second%2==1 && odd)
        {
            odd=0;
        }
        else if(i.second%2==1)
        return false;
    }
    return true;
}
int main()
{
    string s = "aab";
    if(palindromeString(s)) cout<<"TRUE";
    else cout<<"FALSE";
}