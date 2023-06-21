/*Given two strings s and t. The task is to find maximum length of some prefix of the string S which occur in string t as subsequence.

Examples : 

Input : s = "digger"
        t = "biggerdiagram"
Output : 3
digger
biggerdiagram
Prefix "dig" of s is longest subsequence in t.

Input : s = "geeksforgeeks"
        t = "agbcedfeitk"
Output : 4
*/
#include<bits/stdc++.h>
using namespace std;
int maxPrefix(string s,string t)
{
    int count=0;
    for(int i=0;i<t.size();i++)
    {
        if(s.size()==count) break;
        if(t[i]==s[count]) count++;
    }
    return count;
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<maxPrefix(s,t);
}

