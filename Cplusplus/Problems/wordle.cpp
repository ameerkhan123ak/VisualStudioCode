#include<iostream>
using namespace std;
const int STR_MAX = 10;
string RandomString(int str)
{
	string randomStrings[STR_MAX] = {"apple","joker","cards","leafs","lower","power","knife","fried","drove","shove"};
	string result = "";
	for(int i=0;i<str;i++)
	{
		result = randomStrings[rand() % STR_MAX];
    }					 
	return result;
}
int main()
{
	srand(time(NULL));
	int count=0,c=0;
	string s,ans="";
	string correct = "GGGGG";
	string randString = RandomString(5);
	while(count++<5)
	{
		cout<<"ENTER THE WORD: ";
		cin>>s;
		for(int i=0;i<s.length();i++)
		{
			if(s[i] == randString[i])
			{
				ans += "G";
			}
			else 
			{
				ans += "B";
			}
		}
		cout<<"THE WORDLE IS : "<<ans<<endl;
		if(ans == "GGGGG")
		{
			cout<<"THE SENTENCE IS CORRECT : "<<ans<<endl;
			return 0;
		}
		ans = "";
	}
	cout<<"THE CORRECT SENTENCE IS "<<randString<<endl;
}