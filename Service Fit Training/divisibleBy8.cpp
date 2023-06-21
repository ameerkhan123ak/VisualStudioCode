#include<bits/stdc++.h>
using namespace std;

bool checkSubString(string s,string substr)
{
    int index=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==substr[index]) index++;
    }
    return index == substr.size();
}
string findMultiple(string s)
{
    for(int i=0;i<1000;i+=8)
    {
        if(checkSubString(s,to_string(i)))
        {
            return to_string(i);
        }
    }
    return "-1";
}
int main()
{
    string s;
    cin>>s;
    string ans = findMultiple(s);
    cout<<ans;
}
/*
iven a non-negative integer represented in the form of a numeric string str. Remove zero or more characters from the string such that the number becomes divisible by 8. If it is possible, print the string after removing the characters otherwise print -1.
Examples: 

Input: str = “3454” 
Output: 344 
After removing ‘5’, string becomes 344 which is divisible by 8.

Input: str = “111” 
Output: -1 
*/