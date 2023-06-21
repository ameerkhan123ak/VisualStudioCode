#include<bits/stdc++.h>
using namespace std;

int count_vowels(vector<vector<char>> num,int n)
{
    int count=0;
    for(int i=0;i<num[n].size();i++)
    {
        if(num[n][i]=='a' || num[n][i]=='e' || num[n][i]=='i' || num[n][i]=='o' || num[n][i]=='u')
        count++;
    }
    return count;
}
void print_pairs(int n,int arr[])
{
    vector<vector<char>> num =
    {{'z','e','r','o'},
     {'o','n','e'},
     {'t','w','o'},
     {'t','h','r','e','e'},
     {'f','o','u','r'},
     {'f','i','v','e'},
     {'s','i','x'},
     {'s','e','v','e','n'},
     {'e','i','g','h','t'},
     {'n','i','n','e'}};
     
     int vowels_count = 0;
     for(int i=0;i<n;i++)
     {
         vowels_count += count_vowels(num,arr[i]);
     }
     int count=0;
     for(int i=0;i<n-1;i++)
     {
         for(int j=i+1;j<n;j++)
         {
             if(arr[i]+arr[j]==vowels_count) count++;
         }
     }
     switch(count)
     {
         case 0: cout<<"zero"; break;
         case 1: cout<<"one"; break;
         case 2: cout<<"two"; break;
         case 3: cout<<"three"; break;
         case 4: cout<<"four"; break;
         case 5: cout<<"five"; break;
         case 6: cout<<"six"; break;
         case 7: cout<<"seven"; break;
         case 8: cout<<"eight"; break;
         case 9: cout<<"nine"; break;
     }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    print_pairs(n,arr);
}
