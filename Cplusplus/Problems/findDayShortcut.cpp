#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    string findDay(int dd,int mm,int yyyy)
    {
        vector<int> month = {0,3,3,6,1,4,6,2,5,0,3,5};
        vector<int> year = {6,4,2,0,6};
        vector<string> day = {"sunday","monday","tuesday","wednesday","thrusday","friday","saturday"};
        int y = yyyy % 100;
        int temp = y/4;
        int yearcode=0;
        if(yyyy>=1600 && yyyy<=1699) yearcode = 6;
        else if(yyyy>=1700 && yyyy<=1799) yearcode = 4;
        else if(yyyy>=1800 && yyyy<=1899) yearcode = 2;
        else if(yyyy>=1900 && yyyy<=1999) yearcode = 0;
        else if(yyyy>=2000 && yyyy<=2099) yearcode = 6;
        

        int monthcode = month[mm-1];
        int sum = y + temp + yearcode + monthcode + dd;
        return day[sum%7];
    }
};
int main()
{
    int dd,mm,yyyy;
    cin>>dd>>mm>>yyyy;
    Solution sol;
    string ans = sol.findDay(dd,mm,yyyy);
    cout<<ans;
}