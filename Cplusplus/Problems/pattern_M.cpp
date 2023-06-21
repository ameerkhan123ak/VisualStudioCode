#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int start=1,end=n-2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0 || j==n-1) cout<<"*"; //first and last line of M | |
            else if(i==j && i<=n/2) cout<<"*"; /*  line-  \   */
            else if(i==start && end==j)
            {
                cout<<"*"; // line-  / 
                start++;
                end--;
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}

