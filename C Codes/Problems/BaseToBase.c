#include<stdio.h>
void BaseToBase(long long int n,int k)
{
  long long int ans=0,place=1;
  while(n)
  {
    int digit=n%k;
    ans = ans + digit*place;
    place*=10;
    n/=k;
  }
  printf("%lld",ans);
}
int main()
{
  long long int n;
  int k;
  scanf("%lld %d",&n,&k);
  BaseToBase(n,k);
}