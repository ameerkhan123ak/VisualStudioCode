#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<int,map<int,int>> m;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			m[i][j] = i+j;
		}
	}
	for(auto i:m)
	{
		cout<<i.first<<" ";
		for(auto j: i.second)
		cout<<j.first<<" "<<j.second<<" ";
		cout<<endl;
	}
}