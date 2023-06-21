#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

string indianFormat(string s)
{
    int len = s.length();
    for(int i=0;i<len;)
    {
        if(s[i] == ',')
        {
            s.erase(s.begin()+i);
            len--;
            i--;
        }
        else if(s[i]==' ')
        {
            s.erase(s.begin()+i);
            len--;
            i--;
        }
        else 
        i++;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    string output = "";
    for(int i=0;i<len;i++)
    {
        if(i==2) 
        {
            output = output + s[i];
            output = output + ", ";
        }
        else if(i>2 && i%2==0 && i+1<len)
        {
            output = output + s[i];
            output = output + ", ";
        }
        else 
        output = output + s[i];
    }
    reverse(output.begin(),output.end());
    return output;
}
int main()
{
    string s = "123, 456, 789";
    string res = indianFormat(s);
    cout<<res;
}