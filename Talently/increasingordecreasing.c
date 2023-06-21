#include<stdio.h>
int main()
{
  long long int n;
  int t1,t2,t,flag=1;
  scanf("%lld",&n);
  t1=n%10;
  t2=(n/10)%10;
  //printf("%d %d",t1,t2);
  t = t1;
  if(t2<t1)
  {
    while(n){
    int digit=n%10;
    if(digit>t)
    {
      flag=0;
      break;
    }
    n/=10;
    t = digit;
    }
    if(n==0) flag=1;
  }
  else
  {
    while(n)
    {
    int digit=n%10;
    if(digit<t)
    {
      flag=0;
      break;
    }
    n/=10;
    t = digit;
    }
    if(n==0) flag=2;
  }
  if(flag==1) printf("Increasing");
  else if(flag==2) printf("Decreasing");
  else printf("Not");
}