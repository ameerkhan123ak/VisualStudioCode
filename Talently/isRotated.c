#include<stdio.h>
int countDigits(long long int n)
{
  int count=0;
  while(n)
  {
    count++;
    n/=10;
  }
  return count;
}
long long int rotate(long long int n)
{
  int digit = n%10;
  n/=10;
  int c = countDigits(n);
  long long int place = 1;
  while(c--) place*=10;
  place = place*digit;
  place = place + n;
  return place;
}
int main()
{
  long long int a,b;
  scanf("%lld %lld",&a,&b);
  int c = countDigits(a);
  int flag=0;
  for(int i=0;i<=c;i++)
  {
    if(a==b) 
    {
      flag=1;
      break;
    }
    a = rotate(a);
  }
  if(flag) printf("YES");
  else printf("NO");
}