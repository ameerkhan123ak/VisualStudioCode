/*
1. A number should be a natural number 
2. A number should be armstrong number
3. A number should be displayed between interval N1 & N2 
*/
#include<stdio.h>
#include<math.h>
int armstrong(int n)
{
    int temp = n;
    int t=n;
    int p=0;
    while(temp)
    {
        p++;
        temp/=10;
    }
    int ans=0;
    while(n)
    {
        ans += pow(n%10,p);
        n/=10;
    }
    if(ans==t) return 1;
    return 0;
}
int main()
{
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    for(int i=n1;i<=n2;i++)
    {
        if(i>0 && armstrong(i))
        {
            printf("%d ",i);
        }
    }
}