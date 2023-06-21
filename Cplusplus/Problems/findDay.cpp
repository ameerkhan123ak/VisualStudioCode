#include<bits/stdc++.h>
using namespace std;
#define BASE_YEAR 1900
#define BASE_MONTH 1
#define BASE_DAY 1
class Solution
{
    public:
    string findDay(int dd,int mm,int yyyy)
    {
        vector<string> dayData = {"sunday","monday","tuesday","wednesday","thrusday","friday","saturday"};
        int year = calculateYear(yyyy);
        int month = calculateMonth(mm,yyyy) - calculateDay(dd,mm,yyyy);
        int ans = (year + month%7);
        return dayData[ans%7];
    }
    private:
    bool isLeapYear(int yyyy)
    {
        return ((yyyy%4==0) && (yyyy%100!=0)) || (yyyy%400==0);
    }
    int calculateYear(int yyyy)
    {
        int year = 0;
        for(int i=BASE_YEAR;i<yyyy;i++)
        {
            if(isLeapYear(i)) year+=2;
            else year++;
        }
        return year;
    }
    int calculateMonth(int mm,int yyyy)
    {
        vector<int> monthData = {0,31,59,90,120,151,181,212,242,273,303,334};
        int ans = monthData[mm];
        if(isLeapYear(yyyy) && mm>2) ans++;
        return ans; 
    }
    int calculateDay(int dd,int mm,int yyyy)
    {
        vector<int> monthData = {0,31,28,31,30,31,30,31,30,31,30,31};
        int remaining_day = monthData[mm] - dd;
        if(isLeapYear(yyyy)) remaining_day++;
        return remaining_day;
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