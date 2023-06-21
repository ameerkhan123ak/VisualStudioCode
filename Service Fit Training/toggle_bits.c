#include<stdio.h>
int main()
{
    int n;
    int digit,binary=0,i=1;
    int ans=0;
    scanf("%d",&n);
    while(n)
    {
        digit = n%2;
        n/=2;
        digit = digit == 1 ? 0 : 1;
        ans += digit * i;
        i *= 2;
    }
    printf("%d",ans);
}