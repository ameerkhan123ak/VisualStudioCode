#include<iostream>
#include<algorithm>
using namespace std;
void permutation(string s,int start,int end)
{
    if(start==end)
     cout<<s<<endl;
    else 
    {
        for(int i=start;i<=end;i++)
        {
            swap(s[start],s[i]);
            permutation(s,start+1,end);
            swap(s[start],s[i]);
        }
    }
}
int main()
{
    string s = "abc";
    permutation(s,0,s.length()-1);
}

/*
Time complexity: n! * n
Space complexity: 
*/