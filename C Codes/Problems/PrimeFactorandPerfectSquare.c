#include<stdio.h>
#include<math.h>
int checkPerfectSquare(int n)
{
    if(sqrt(n) == (int)sqrt(n)) return 1;
    return 0;
}
void checkFactor(int n)
{
    int flag=0;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0) 
        {
            if(checkPerfectSquare(i))
            {
                flag=1;
                break;
            }
        }
    }
    if(flag) printf("%d ",n);
}
int main()
{
    int start = 100;
    int end = 150;
    for(int i=start;i<=end;i++)
    {
        checkFactor(i);
    }
}