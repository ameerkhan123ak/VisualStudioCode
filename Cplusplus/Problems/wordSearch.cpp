#include<iostream>
#include<string>
using namespace std;

bool checkSubstring(string s,string word)
{
    int len = 3;
    for(int i=0;i<s.length();i++)
    {
        if(s.substr(i,i+3) == word) 
        {
            cout<<s.substr(i,i+3)<<endl;
            return true;
        }
        cout<<s.substr(i,i+3)<<endl;
    }
    return false;
}
void horizontalTraversal(char arr[][5],int rowsize,int colsize,string word)
{
  for(int i=0;i<rowsize;i++)
  {
    string s = "";
    for(int j=0;j<colsize-2;j++)
    {
      s = s + arr[i][j];
    }
    bool b = checkSubstring(s,word);
    if(b) cout<<"horizontal"<<endl;
  }
  printf("-1");
}
void verticalTraversal(char arr[][5],int rowsize,int colsize,string word,int l)
{
  for(int i=0;i<rowsize;i++)
  {
    string s = "";
    for(int j=0;j<colsize;j++)
    {
        s = s + arr[j][i];
    }
    checkSubstring(s,word);
  }
}
int main()
{
  char arr[][5] = {{'w','e','l','c','o'},
                   {'m','e','t','o','z'},
                   {'o','h','o','c','o'},
                   {'r','p','o','r','a'},
                   {'t','i','o','n'}};

//   int rowsize=5,colsize=5;
//   string word = "too";
//   int l = word.length();
//   int l2 = l - 2;
//   int subsize = 3;
//   verticalTraversal(arr,rowsize,colsize,word,l);
    for(int i=0;i<5;i++)
        {
            string s = "";
            for(int j=0;j<5;j++)
            {
                s = s + arr[j][i];
            }
            for(int k=0;k<2;k++)
            {
                cout<<(s.substr(k,k+3))<<" ";
            }
            cout<<endl;
        } 
}