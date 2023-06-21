#include<stdio.h>
int countDigits(long long int n)
{
  int count=0;
  while(n)
  {
    count++;
    //printf("%d %lld\n",count,n);
    n/=10;
  }
  return count;
}
long long int reverse(long long int n)
{
  long long int rev =0 ;
  while(n)
  {
    rev = rev*10 + n%10;
    n/=10;
  }
  return rev;
}
int main()
{
  long long int n,dp1=1,dp2=1,digit=0,t;
  int x,y,a,b,c=0;
  //printf("%d",c);
  scanf("%lld %d %d",&n,&x,&y);
  c = countDigits(n);
  a=x;b=y;
  while(x) 
  {
    dp1 = dp1*10;
    x--;
  }
  while(y)
  {
    dp2 = dp2*10;
    y--;
  }
  dp1/=10; dp2/=10;
  int d1,d2;
  d1 = (n/dp1)%10;
  d2 = (n/dp2)%10; 
  while(b--)
  {
    digit = digit*10 + n%10;
    n/=10;
  }
  n = n*10 + d1;
  int c2 = countDigits(n);
  while(c>c2)
  {
    n = n*10 + digit%10;
    c2 = countDigits(n);
    digit=digit/10;
  }
  digit=0;
  while(a--)
  {
    digit = digit*10 + n%10;
    n/=10;
  }
  n = n*10 + d2;
  c2 = countDigits(n);
  while(c>c2)
  {
    n = n*10 + digit%10;
    digit /= 10;
    c2 = countDigits(n);
  }
  printf("%lld",n);
}