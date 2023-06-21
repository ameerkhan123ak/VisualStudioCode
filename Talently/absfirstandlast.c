#include<stdio.h>
#include<math.h>
int main()
{
  long long int n,t,left,right,power=1;
  scanf("%lld",&n);
  t=n;
  int d=0,sum=0,diff=0,left_digit,right_digit;
  while(t)
  {
    t/=10;
    d++;
    power = power * 10;
  }
  left = power/10;
  right = 1;
  for(int i=0;i<d/2;i++)
  {
    left_digit = (n/left)%10;
    right_digit = (n/right)%10;
    left=left/10;
    right = right*10;
    diff = abs(left_digit - right_digit);
    sum = sum + diff;
  }
  if(d%2==1)
  {
    sum += (n/left)%10;
  }
  printf("%d",sum);
}