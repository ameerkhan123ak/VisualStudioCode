#include<stdio.h>
int main()
{
  long long int n,t,dp1=1,dp2=1,d1=1,d2=1,digit=0;
  int x,y,a,b,p1,p2;
  scanf("%lld %d %d",&n,&x,&y);
  a=x; b=y;
  t=n;
  while(a--) dp1*=10; dp1/=10;
  while(b--) dp2*=10; dp2/=10;
  d1=(n/dp1)%10; 
  d2=(n/dp2)%10;
  //printf("%d %d",d1,d2);
  while(x--) 
  {
    digit = digit*10 + n%10;
    n/=10;
  }
  digit/=10;
  n = n*10 + d2; 
  //printf("%lld",n);
  while(digit)
  {
    n = n*10 + digit%10;
    digit/=10;
  }
  digit=0;
  while(y--)
  {
    digit = digit*10 + n%10;
    n/=10;
  }
  digit/=10;
  n = n*10 + d1;
  while(digit)
  {
    n = n*10 + digit%10;
    digit/=10;
  }
  printf("%lld",n);
}