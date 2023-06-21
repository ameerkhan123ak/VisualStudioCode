#include<stdio.h>
long long int reverse(long long int n)
{
  long long int rev = 0;
  while(n)
  {
    rev = rev*10 + n%10;
    n/=10;
  }
  return rev;
}
int main()
{
  long long int n,odd=0,even=0;
  int k;
  scanf("%lld %d",&n,&k);
  while(n)
  {
    int digit=n%10;
    if(digit%2==0) even=even*10+digit;
    else odd=odd*10+digit;
    n/=10;
  }
  if(k==1)
  {
    even = reverse(even);
    while(odd)
    {
      even = even*10 + odd%10;
      odd/=10;
    }
    printf("%lld",even);
  }
  else 
  {
    odd = reverse(odd);
    while(even)
    {
      odd = odd*10 + even%10;
      even /= 10;
    }
    printf("%lld",odd);
  }
}