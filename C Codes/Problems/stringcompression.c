// aabcccccaaa
#include<stdio.h>
#include<string.h>
int main()
{
  char str[] = "aabcccccaaa";
  int count=1;
  int n = strlen(str);
  for(int i=0;i<n;i++)
  {
    if(str[i]==str[i+1])
    count++;
    else
    {
      printf("%c%d",str[i],count);
      count=1;
    }
  }
}