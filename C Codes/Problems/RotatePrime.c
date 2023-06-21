#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int checkPrime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    if(n%i==0) return 0;
    return 1;
}
int countDigits(int n)
{
    int count=0;
    while(n)
    {
        n/=10;
        count++;
    }
    return count;
}
int findFirst(int n)
{
    int ans = 1;
    while(n--)
    {
        ans *= 10;
    }
    ans/=10;
    return ans;
}
int main()
{
    int n = 415;
    int b = checkPrime(n); printf("%d ",b);
    int digits = countDigits(n);
    int first = findFirst(digits);
    while(checkPrime(n)!=true)
    {
        int last = n%10;
        int temp = n/10;
        n = (first*last) + temp;
        printf("%d ",n);
    }
    printf("%d ",n);
}